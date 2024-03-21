/*
  DemoVietnamese: print to a LCD2004A (Japanese ROM) using I2C (PCF8574)
  a Vietnamese text and clear the screen before printing another text.
  Author: Le Phuoc Loc <phuocloc@gmail.com>

  Note:
  - Include LCDI2C_Viet.h for the main class and customized characters for Vietnamese
    => All Vietnamese letters and degree (°) symbol can be printed.
  - Include ROM_Standard_JP.h for Greek symbol mappings on LCD2004A Japanese ROM
    => All English letters, sign(÷√∞→←), Greek(ΣΩαβδεθμπρ), currency(¥) symbols can be printed.
  - If no longer room to print the next word in current line, it'll be printed in next line.
  - Max 8 Vietnamese letters with diacritics printed on a screen, otherwise diacritics removed.

  https://github.com/locple/LiquidCrystal_I2C_UTF8
*/

#include <LCDI2C_Viet.h>
#include <ROM_Standard_JP.h>

LiquidCrystal_I2C_Viet lcd(0x27, 20, 4);  // I2C address: 0x27; Display size: 20x4

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.println("CAO ĐẲNG CÔNG THƯƠNG VIỆT NAM");
  delay(3000); lcd.clear();
  lcd.print("Cao đẳng Công thương Việt Nam");
}

void loop() {}
