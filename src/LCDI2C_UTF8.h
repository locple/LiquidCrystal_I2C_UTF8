/*
  LiquidCrystal_I2C_UTF8 class header file

  Base class for printing UTF8 strings to I2C LCD
  Remember to include appropriate ROM header file with your LCD controller/driver

  Created 17 Mar 2024
  Author: Le Phuoc Loc <phuocloc@gmail.com>

  https://github.com/locple/LiquidCrystal_I2C_UTF8
*/

#ifndef LCDI2C_UTF8
#define LCDI2C_UTF8
#include <LiquidCrystal_I2C.h>

#define CGRAM_SIZE 8
#define NOTFOUND 255          // Default error code

// Struct for a symbol character
struct Symbol {
  wchar_t   code;     // Letter / symbol code point
  char      link;     // Linked character
};

// Struct for a unicode letter
struct Letter {
  wchar_t   code;     // Unicode code point (2 bytes)
  uint8_t   mapT[5];	// Tranposed bitmap matrix (5x8) to render (use 5x8 instead of 8x8 for saving RAM)
};

#ifndef LCDI2C_Customization
extern const unsigned int LetterNum = 1;
// List of custom Unicode characters
extern const struct Letter Letters [LetterNum] = {
  {0x00B0, {0b00000000,0b11100000,0b10100000,0b11100000,0b00000000}}  // °	(degree symbol)
};
#endif  // LCDI2C_Customization

class LiquidCrystal_I2C_UTF8 : public LiquidCrystal_I2C {
public:
  LiquidCrystal_I2C_UTF8(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows, uint8_t longest_wordlength = 0);
  void      begin(uint8_t cols, uint8_t lines, uint8_t dotsize);
  void      clear();                      // Clear LCD screen
  void      home();                       // Move cursor to top first position
  void      setCursor(uint8_t col, uint8_t row);
  uint8_t   getCursorColumn();
  uint8_t   getCursorRow();
  using     LiquidCrystal_I2C::write;
  // Print methods with: moving to new line when reaching last column, pausing some times before next page
  virtual   size_t    print(const char[], int pause);
  size_t    print(const String &, int pause = 0);
  size_t    println(const char[], int pause = 0);
  size_t    println(const String &, int pause = 0);
  size_t    println(void);

private:
  uint8_t   inUseLetters[CGRAM_SIZE] = {  // Indexes of Vietnamese letters in use in CGRAM. NOTFOUND: unallocated
            NOTFOUND, NOTFOUND, NOTFOUND, NOTFOUND, NOTFOUND, NOTFOUND, NOTFOUND, NOTFOUND};  // Change this with CGRAM_SIZE
  uint8_t   charmap[8];                   // Template used by createChar()
  uint8_t   longestWordLength;
  uint8_t   checkNextWordCol;
  void      tranpose(const uint8_t src[], uint8_t dst[]);
  void      clearLetters();

protected:
  uint8_t   nextWordEndCol = 0;
  uint8_t   colNum, rowNum;
  uint8_t   cursorColumn = 0, cursorRow = 0;
  uint8_t   inUseLettersNum = 0;          // Number of elements of inUseLetters
  void      newLine();
  uint8_t   createLetter(uint8_t);
  uint8_t   getUTF8ByteNum(const char*);
  wchar_t   getUTF8CodePoint(const char*, uint8_t&);
  uint8_t   nextWordLength(const char*, uint16_t);
  uint8_t   getLetterIndex(wchar_t);
  uint8_t   getInUseLetterIndexOrder(uint8_t);
  char      getSymbolLink(wchar_t);
  virtual   char      getAlternativeLetter(wchar_t);
};

#endif  // LCDI2C_UTF8