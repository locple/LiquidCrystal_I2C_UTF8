#include <Arduino.h>
#define LCDI2C_Customization  // to ignore LetterNum and Letters definitions in LCDI2C_UTF8.h
#include "LCDI2C_UTF8.h"

extern const unsigned int LetterNum;
extern const struct Letter Letters[];
extern const unsigned int SymbolNum;
extern const struct Symbol Symbols[];

inline uint8_t   LiquidCrystal_I2C_UTF8::getCursorColumn()  { return cursorColumn; }
inline uint8_t   LiquidCrystal_I2C_UTF8::getCursorRow()     { return cursorRow; }

// Tranpose charmap "src" 5x8 to charmap "dst" 8x5
void LiquidCrystal_I2C_UTF8::tranpose(const uint8_t src[], uint8_t dst[]) {
  uint8_t element, mask = 0b10000000;
  memset(dst, 0, 8);
  for (uint8_t i = 0; i < 8; i++) {
    for (uint8_t j = 0; j < 5; j++) {
    	element = ((src[j] & mask) << i) >> j + 3;
   		dst[i] |= element;
    }
  	mask >>= 1;
  }
}

// Dismiss all custom letters currently used in CGRAM
void LiquidCrystal_I2C_UTF8::clearLetters() {
  inUseLettersNum = 0;
  memset(inUseLetters, NOTFOUND, CGRAM_SIZE);
}

// Create new letter having index "idx" ferencing to "Letters"
uint8_t LiquidCrystal_I2C_UTF8::createLetter(uint8_t idx) {
  uint8_t placeOrd = inUseLettersNum++;

  // Create new coresponding letter in CGRAM
  tranpose(Letters[idx].mapT, charmap);
  LiquidCrystal_I2C::createChar(placeOrd, charmap);
  inUseLetters[placeOrd] = idx;

  return placeOrd;
}

// Return index of letter "c" referencing to "Letters"
uint8_t LiquidCrystal_I2C_UTF8::getLetterIndex(wchar_t c) {
  for (int idx = 0; idx < LetterNum; idx++)
    if (Letters[idx].code == c) return idx;

  return NOTFOUND;
}

// Check the existing of a letter index in CGRAM
uint8_t LiquidCrystal_I2C_UTF8::getInUseLetterIndexOrder(uint8_t idx) {
  for (uint8_t ord = 0; ord < inUseLettersNum; ord++)
    if (inUseLetters[ord] == idx) return ord;

  return NOTFOUND;
}

// Find corresponding symbols in LCD character table
char LiquidCrystal_I2C_UTF8::getSymbolLink(wchar_t c) {
  for (int idx = 0; idx < SymbolNum; idx++)
    if (c == Symbols[idx].code)
      return Symbols[idx].link;

  return NOTFOUND;
}

// Each language may implements its own getAlternativeLetter()
// Default implementation:  ////
char LiquidCrystal_I2C_UTF8::getAlternativeLetter(wchar_t c) {
  return char(c);
}

// Get byte number of the UTF8 codes in text reperenting the letter
uint8_t LiquidCrystal_I2C_UTF8::getUTF8ByteNum(const char* text) {
  if (text[0] < 0x80) return 1;
  else if (text[0] < 0xC2) return 0;  // Invalid UTF8
  uint8_t byte0 = text[0], num = 1;

  // Scan first byte for UTF8 byte number (= total of first bits in this byte)
  for (int i = 0; i < 4; i++) {   // max 4 bytes (presented by 4 first bits)
    byte0 <<= 1;
    if (byte0 & 0x80) num++;
    else break;
  }

  // Check the total of following bytes
  for (int i = 1; i < num; i++)
    if ((text[i] >> 6) != 0x02) return 0; // Invalid UTF8

  return num;
}

// Get code point from UTF8 codes reprenting the letter
wchar_t LiquidCrystal_I2C_UTF8::getUTF8CodePoint(const char* text, uint8_t& nbytes) {
  wchar_t result = 0;
  nbytes = 1;
  if (text[0] < 0x80) return (wchar_t) text[0];
  else if (text[0] < 0xC2) return result;  // Invalid UTF8
  wchar_t units[4];  // However we only process 2-byte or 3-byte codes (Vietnamese code points)
  uint8_t byte0 = text[0];

  // Scan first byte for UTF8 byte number (= total of first bits in this byte)
  for (int i = 0; i < 4; i++) {   // max 4 bytes (presented by 4 first bits)
    byte0 <<= 1;
    if (byte0 & 0x80) {
      nbytes++;
      units[i+1] = text[i+1] & 0x7F;  // Extract each component of the code point
    } else {
      units[0] = byte0 >> nbytes;
      for (int j = nbytes; j > 0; j--) {
        units[j-1] <<= 6 * (nbytes - j);
        result += units[j-1];
      }
      return result;
    }
  }

  return result; // Invalid UTF8
}

uint8_t LiquidCrystal_I2C_UTF8::nextWordLength(const char* text, uint16_t start) {
  uint16_t i = start, nbytes, length = 0;

  while (text[i] != '\0') {                     // Find first non-letter character from start
    if ((text[i] < 0x30) ||                     // Below '0'
        (text[i] > 0x39 && text[i] < 0x41) ||   // Between '9' and 'A'
        (text[i] > 0x5A && text[i] < 0x61) ||   // Between 'Z' and 'a'
        (text[i] > 0x7A && text[i] < 0x80)) {   // Between 'z' and first multi-byte UTF8 character
          return length;
    } else {                                    // Go through UTF8 characters
        nbytes = getUTF8ByteNum(&text[i]);
        if (nbytes) {
          length++;
          i += nbytes;
        } else i++;
      } // else
    } // if

  return length;
}

// Printing char* 'text' that contains multibyte UTF8 letters,
// automatically moving to new line when reaching last column
// 'pause' >= 0: delay 'pause' seconds before printing on next page
size_t LiquidCrystal_I2C_UTF8::print(const char text[], int pause) {
  uint8_t idx, ord, length, nbytes;
  wchar_t code; char link;
  size_t nletters = 0;
  bool ignore_space;

  for (uint16_t i = 0; text[i] != '\0'; i += nbytes, nletters++) {
    code = getUTF8CodePoint(&text[i], nbytes);

    ignore_space = false;
    if (cursorColumn > nextWordEndCol) {
      length = nextWordLength(text, i);       // Note that we don't check again on the same word
      if (length) nextWordEndCol = (length > colNum? colNum - 1 : cursorColumn + length - 1);

      if (nextWordEndCol >= colNum)           // Not enough columns to print the whole word?
        if ((cursorRow + 1) % rowNum) {       // Print it if next row exists
          ignore_space = true;
          newLine();                          // Automatically move to the next row to print the whole next word
        } else {                              // No row left to print
          if (pause > 0) delay(pause * 1000);
          clear();                            // Automatically clear LCD and CGRAM for printing the whole next word
        }
    } // if pause

    if (code < 0x7E)                          // ASCII character?
      if (code > 0x1F) {                      // Printable
        if (!ignore_space || code != 0x20)
          write(char(code));
      } else                                // Non-printable
        write('*');
    else {                                    // Unicode character
      idx = getLetterIndex(code);
      if (idx == NOTFOUND) {
        link = getSymbolLink(code);
        if (link != NOTFOUND)                 // Link to a symbol?
          write(link);
        else                                  // Unknown unicode character
          write('*');
      } else {                                // Declared unicode letter
        ord = getInUseLetterIndexOrder(idx);
        if (ord == NOTFOUND) {                // None exists in CGRAM
          if (inUseLettersNum < CGRAM_SIZE)   // Run out of CGRAM?
            ord = createLetter(idx);          // No -> Create a new letter in CGRAM
          else                                // Yes -> Replace with alternative letter
            ord = (uint8_t) getAlternativeLetter(Letters[idx].code);
        }
        LiquidCrystal_I2C::setCursor(cursorColumn, cursorRow);  // Fix wrong cursor moving when creating custom character
        write(ord);
      } // If Declared unicode letter
    } // If Unicode character

    if (!ignore_space || code != 0x20)        // The leading space not printed after auto moving, so don't move the cursor
      if (++cursorColumn == colNum)           // Check if the cursor exceeds max column of LCD screen?
        if (text[i + nbytes] != '\0')         // Check if the end of 'text'?
          if ((cursorRow + 1) % rowNum) {     // Check if existing rows left to print?
            ignore_space = true;
            newLine();                        // Automatically move to the next row if the cursor exceeds colNum
          } else {
            if (pause >= 0) delay(pause * 1000);
            clear();                          // Automatically clear LCD and CGRAM if no space left to print
          }
  } // for

  return nletters;
}

// Printing String 'text' that contains multibyte UTF8 letters,
// automatically moving to new line when reaching last column
// 'pause' >= 0: delay 'pause' seconds before printing on next page
size_t LiquidCrystal_I2C_UTF8::print(const String& text, int pause) {
  unsigned int size = text.length() + 1;
  char buff[size];
  text.toCharArray(buff, size);
  return print(buff, pause);
}

// Printing char* 'text' that contains multibyte UTF8 letters + new line,
// automatically moving to new line when reaching last column
// 'pause' >= 0: delay 'pause' seconds before printing on next page
size_t LiquidCrystal_I2C_UTF8::println(const char text[], int pause) {
  size_t len = print(text, pause);
  newLine();
  return len;
}

// Printing String 'text' that contains multibyte UTF8 letters + new line,
// automatically moving to new line when reaching last column
// 'pause' >= 0: delay 'pause' seconds before printing on next page
size_t LiquidCrystal_I2C_UTF8::println(const String& text, int pause) {
  size_t len = print(text, pause);
  newLine();
  return len;
}

size_t LiquidCrystal_I2C_UTF8::println(void) {
  newLine();
  return 0;
}

void LiquidCrystal_I2C_UTF8::newLine() {
  cursorColumn = 0;
  cursorRow = ++cursorRow % rowNum;
  nextWordEndCol = checkNextWordCol;
  LiquidCrystal_I2C::setCursor(cursorColumn, cursorRow);
}

void LiquidCrystal_I2C_UTF8::clear() {
  clearLetters();
  cursorColumn = 0; cursorRow = 0;
  nextWordEndCol = checkNextWordCol;
  LiquidCrystal_I2C::clear();
}

void LiquidCrystal_I2C_UTF8::home() {
  cursorColumn = 0; cursorRow = 0;
  nextWordEndCol = checkNextWordCol;
  LiquidCrystal_I2C::home();
}

void LiquidCrystal_I2C_UTF8::setCursor(uint8_t col, uint8_t row) {
  if (row >= rowNum) row %= rowNum;
  cursorColumn = col; cursorRow = row;
  nextWordEndCol = checkNextWordCol;
  LiquidCrystal_I2C::setCursor(col, row);
}

LiquidCrystal_I2C_UTF8::LiquidCrystal_I2C_UTF8(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows, uint8_t longest_wordlength)
  : LiquidCrystal_I2C(lcd_Addr, lcd_cols, lcd_rows) {
  colNum = lcd_cols;
  rowNum = lcd_rows;
  longestWordLength = longest_wordlength;
  if (longestWordLength == 0 || longestWordLength > colNum)
    checkNextWordCol = 0;       // check next word from first column
  else
    checkNextWordCol = colNum - longestWordLength;
}

void LiquidCrystal_I2C_UTF8::begin(uint8_t cols, uint8_t lines, uint8_t dotsize) {
  colNum = cols;
  rowNum = lines;
  if (longestWordLength == 0 || longestWordLength > colNum)
    checkNextWordCol = 0;       // check next word from first column
  else
    checkNextWordCol = colNum - longestWordLength;
  LiquidCrystal_I2C::begin(cols, lines, dotsize);
}