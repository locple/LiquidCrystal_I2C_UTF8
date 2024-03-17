/*
  Russian standard ROM header file

  Character mappings for LCDs using following controller/driver chips:
  - Surenoo SLC Russian series

  Created 17 Mar 2024
  Author: Le Phuoc Loc

  https://github.com/locple/LiquidCrystal_I2C_UTF8
*/

#ifndef LCDI2C_ROM
#define LCDI2C_ROM

extern const unsigned int  SymbolNum = 74;
// List of some symbols in Russian font table built in the ROM
extern const struct Symbol Symbols [SymbolNum] = {
  {0x21B5, 0x7E},   // ↵ enter
  {0x2191, 0xD9},   // ↑ up arrow
  {0x2193, 0xDA},   // ↓ down arrow
  {0x2192, 0xC9},   // → right arrow
  {0x2190, 0xC8},   // ← left arrow
  {0x00A2, 0x5C},   // ¢ Cent
  {0x00A3, 0xCF},   // £ Pound
  {0x00D7, 0xD5},   // × Multiplication
  {0x0401, 0xA2},   // Ё
  {0x0410, 0x41},   // А
  {0x0411, 0xA0},   // Б
  {0x0412, 0x42},   // В
  {0x0413, 0xA1},   // Г
  {0x0414, 0xE0},   // Д
  {0x0415, 0x45},   // Е
  {0x0416, 0xA3},   // Ж
  {0x0417, 0xA4},   // З
  {0x0418, 0xA5},   // И
  {0x0419, 0xA6},   // Й
  {0x041A, 0x4B},   // К
  {0x041B, 0xA7},   // Л
  {0x041C, 0x4D},   // М
  {0x041D, 0x48},   // Н
  {0x041E, 0x4F},   // О
  {0x041F, 0xA8},   // П
  {0x0420, 0x50},   // Р
  {0x0421, 0x43},   // С
  {0x0422, 0x54},   // Т
  {0x0423, 0xA9},   // У
  {0x0424, 0xAA},   // Ф
  {0x0425, 0x58},   // Х
  {0x0426, 0xE1},   // Ц
  {0x0427, 0xAB},   // Ч
  {0x0428, 0xAC},   // Ш
  {0x0429, 0xE2},   // Щ
  {0x042A, 0xAD},   // Ъ
  {0x042B, 0xAE},   // Ы
  {0x042C, 0x62},   // Ь (b)
  {0x042D, 0xAF},   // Э
  {0x042E, 0xB0},   // Ю
  {0x042F, 0xB1},   // Я
  {0x0430, 0x61},   // а
  {0x0431, 0xB2},   // б
  {0x0432, 0xB3},   // в
  {0x0433, 0xB4},   // г
  {0x0434, 0xE3},   // д
  {0x0435, 0x65},   // е
  {0x0436, 0xB6},   // ж
  {0x0437, 0xB7},   // з
  {0x0438, 0xB8},   // и
  {0x0439, 0xB9},   // й
  {0x043A, 0xBA},   // к
  {0x043B, 0xBB},   // л
  {0x043C, 0xBC},   // м
  {0x043D, 0xBD},   // н
  {0x043E, 0x6F},   // о
  {0x043F, 0xBE},   // п
  {0x0440, 0x70},   // р
  {0x0441, 0x63},   // с
  {0x0442, 0xBF},   // т
  {0x0443, 0x79},   // у
  {0x0444, 0xE4},   // ф
  {0x0445, 0x78},   // х
  {0x0446, 0xE5},   // ц
  {0x0447, 0xC0},   // ч
  {0x0448, 0xC1},   // ш
  {0x0449, 0xE6},   // щ
  {0x044A, 0xC2},   // ъ
  {0x044B, 0xC3},   // ы
  {0x044C, 0xC4},   // ь
  {0x044D, 0xC5},   // э
  {0x044E, 0xC6},   // ю
  {0x044F, 0xC7},   // я
  {0x0451, 0xB5}    // ё
};

#endif  // LCDI2C_ROM