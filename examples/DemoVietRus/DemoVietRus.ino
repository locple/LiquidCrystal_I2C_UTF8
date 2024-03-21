/*
  DemoVietRus: print both Vietnamese and Russian texts to
  a Surenoo SLC1602 LCD (Russian ROM) using I2C (PCF8574)
  Author: Le Phuoc Loc <phuocloc@gmail.com>

  Note:
  - Include LCDI2C_Viet.h for the main class and customized characters for Vietnamese
    => All Vietnamese letters and degree (°) symbol can be printed.
  - Include ROM_Surenoo_RU.h for Russian letter mappings on Surenoo SLC1602 (Russian)
    => All Russian and English letters, arrow (↵↑→↓←), currency (¢£), (×) symbols can be printed.

  https://github.com/locple/LiquidCrystal_I2C_UTF8
*/

#include <LCDI2C_Viet.h>
#include <ROM_Surenoo_RU.h>

LiquidCrystal_I2C_Viet lcd(0x27, 16, 2);  // I2C address: 0x27; Display size: 16x2

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.println("Dòng tiếng Việt!");
  lcd.println("Русская надпись!");
}

void loop() {}
