/*
  Latin standard ROM header file

  Character mappings for LCDs using following controller/driver chips:
  - Wuxi AIP31066W2
  - Sitronix ST7066-0B

  Created 17 Mar 2024
  Author: Le Phuoc Loc <phuocloc@gmail.com>

  https://github.com/locple/LiquidCrystal_I2C_UTF8
*/

#ifndef LCDI2C_ROM
#define LCDI2C_ROM

extern const unsigned int  SymbolNum = 33;
// List of some symbols in Latin font table built in the ROM
extern const struct Symbol Symbols [SymbolNum] = {
  {0x00B1, 0x10},   // ± Plus-Minus
  {0x2248, 0x1D},   // ≈ almost equal
  {0x00B2, 0x1E},   // ² power of 2
  {0x00B3, 0x1F},   // ³ power of 3
  {0x00A2, 0xA4},   // ¢ Cent
  {0x00A3, 0xA5},   // £ Pound
  {0x00A5, 0xA6},   // ¥ Yen
  {0x00D7, 0xB7},   // × Multiplication
  {0x00F7, 0xB8},   // ÷ Division
  {0x2264, 0xB9},   // ≤ LTE
  {0x2265, 0xBA},   // ≥ GTE
  {0x221A, 0xBE},   // √ sqrt
  {0x221E, 0xC2},   // ∞ infinity
  {0x21B5, 0xC4},   // ↵ enter
  {0x2191, 0xC5},   // ↑ up arrow
  {0x2193, 0xC6},   // ↓ down arrow
  {0x2192, 0xC7},   // → right arrow
  {0x2190, 0xC8},   // ← left arrow
  {0x03A3, 0xDA},   // Σ sigma (capital)
  {0x03A9, 0xDE},   // Ω omega (capital)
  {0x03B1, 0xDF},   // α alpha
  {0x03B2, 0xE0},   // β beta
  {0x03B3, 0xE1},   // γ gamma
  {0x03B4, 0xE2},   // δ delta
  {0x03B5, 0xE3},   // ε epsilon
  {0x03B7, 0xE5},   // η eta
  {0x03B8, 0xE6},   // θ theta
  {0x03BC, 0xEA},   // μ mu
  {0x03C0, 0xED},   // π pi
  {0x03C1, 0xEE},   // ρ rho
  {0x03C3, 0xEF},   // σ sigma
  {0x03C8, 0xF3},   // ψ psi
  {0x03C9, 0xF4}    // ω omega
};

#endif  // LCDI2C_ROM