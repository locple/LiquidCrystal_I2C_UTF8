/*
  DemoVietRus: print both Vietnamese and Russian texts to
  a Surenoo SLC1602 LCD (Russian ROM) using I2C (PCF8574)
  Author: Le Phuoc Loc

  Circuit:
  - Arduino Uno/Mini/Nano:  A5 (SCL),   A4 (SDA)
  - Arduino Micro:          3 (SCL),    2 (SDA)
  - LOLIN D1 Mini:          5 (SCL),    4 (SDA)
  - ESP8266:                D1 (SCL),   D2 (SDA)
  - LOLIN D32:              22 (SCL),   21 (SDA)
  - ESP32:                  D22 (SCL),  D21 (SDA)

  Coding: steps to follow
  - Include LCDI2C_Viet.h for the main class and customized characters for Vietnamese
    => All Vietnamese letters and degree (°) symbol can be printed.
  - Include ROM_Surenoo_RU.h for Russian letter mappings on Surenoo SLC1602 (Russian)
    => All Russian and English letters, arrow (↵↑→↓←), currency (¢£), (×) symbols can be printed.
  - Create LiquidCrystal_I2C_Viet object with I2C address=0x27, LCD size: 16 columns, 2 rows
  - ::begin(): Initialize the LCD
  - ::backlight(): Turn on the LCD backlight
  - ::print(text): print text (String or char[]) to LCD
 
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