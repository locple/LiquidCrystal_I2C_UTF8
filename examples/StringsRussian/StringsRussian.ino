/*
  StringsRussian: print multiple strings from a Russian song
  to a LCD1602A (Russian/Latin ROM) using I2C (PCF8574)
  Author: Le Phuoc Loc <phuocloc@gmail.com>

  Circuit:
  - Arduino Uno/Mini/Nano:  A5 (SCL),   A4 (SDA)
  - Arduino Micro:          3 (SCL),    2 (SDA)
  - LOLIN D1 Mini:          5 (SCL),    4 (SDA)
  - ESP8266:                D1 (SCL),   D2 (SDA)
  - LOLIN D32:              22 (SCL),   21 (SDA)
  - ESP32:                  D22 (SCL),  D21 (SDA)

  Coding: steps to follow
  - Include LCDI2C_UTF8.h for the main base class and one customized character (°):
    => Degree (°) symbol can be printed.
  - Include ROM_Standard_RU.h for Russian letter mappings on LCD1602A Russian/Latin ROM
    => Russian capital letters, all English letters, sign(±²³×÷≤≥∞↵↑→↓←), Greek(ΣΩαβδεθμπσω), currency(¢£¥) symbols can be printed.
  - Create LiquidCrystal_I2C_UTF8 object with I2C address=0x27, LCD size: 16 columns, 2 rows
  - ::init(): Initialize the LCD
  - ::backlight(): Turn on the LCD backlight
  - ::print(text): print text (String or char[]) to LCD
    If no longer room to print the next word in current line, it'll be printed in next line.
    ::print(text, nsec): print long text with pause 'nsec' seconds
    If the screen is full, wait 'nsec' seconds for audience to read before printing the next part on next screen.

  https://github.com/locple/LiquidCrystal_I2C_UTF8
*/

#include <LCDI2C_UTF8.h>
#include <ROM_Standard_RU.h>

LiquidCrystal_I2C_UTF8 lcd(0x27, 16, 2);  // I2C address: 0x27; Display size: 16x2

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.println("ПОДМОСКОВНЫЕ ВЕЧЕРА");
  delay(3000); lcd.clear();
  lcd.println("НЕ СЛЫШНЫ В САДУ ДАЖЕ ШОРОХИ, ВСЁ ЗДЕСЬ ЗАМЕРЛО ДО УТРА. ЕСЛИ Б ЗНАЛИ ВЫ, КАК МНЕ ДОРОГИ, ПОДМОСКОВНЫЕ ВЕЧЕРА", 3);
  delay(3000); lcd.clear();
  lcd.println("РЕЧКА ДВИЖЕТСЯ И НЕ ДВИЖЕТСЯ, ВСЯ ИЗ ЛУННОГО СЕРЕБРА. ПЕСНЯ СЛЫШИТСЯ И НЕ СЛЫШИТСЯ, В ЭТИ ТИХИЕ ВЕЧЕРА", 3);
  delay(3000); lcd.clear();
  lcd.println("ЧТО Ж ТЫ, МИЛАЯ, СМОТРИШЬ ИСКОСА, НИЗКО ГОЛОВУ НАКЛОНЯ", 3);
  delay(3000); lcd.clear();
  lcd.println("ТРУДНО ВЫСКАЗАТЬ И НЕ ВЫСКАЗАТЬ. ВСЁ, ЧТО НА СЕРДЦЕ У МЕНЯ", 3);
  delay(3000); lcd.clear();
  lcd.println("А РАССВЕТ УЖЕ ВСЁ ЗАМЕТНЕЕ. ТАК, ПОЖАЛУЙСТА, БУДЬ ДОБРА", 3);
  delay(3000); lcd.clear();
  lcd.println("НЕ ЗАБУДЬ И ТЫ ЭТИ ЛЕТНИЕ, ПОДМОСКОВНЫЕ ВЕЧЕРА", 3);
}

void loop() {}