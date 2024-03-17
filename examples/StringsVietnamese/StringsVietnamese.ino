/*
  StringsVietnamese: print multiple strings from a Vietnamese poem
  to a LCD2004A (Japanese ROM) using I2C (PCF8574)
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
  - Include ROM_Standard_JP.h for Greek symbol mappings on LCD2004A Japanese ROM
    => All English letters, sign(÷√∞→←), Greek(ΣΩαβδεθμπρ), currency(¥) symbols can be printed.
  - Create LiquidCrystal_I2C_Viet object with I2C address=0x27, LCD size: 20 columns, 4 rows
  - ::begin(): Initialize the LCD
  - ::backlight(): Turn on the LCD backlight
  - ::print(text): print text (String or char[]) to LCD
    If no longer room to print the next word in current line, it'll be printed in next line.
    Note: max 8 Vietnamese letters with diacritics printed on a screen, otherwise diacritics removed.

  https://github.com/locple/LiquidCrystal_I2C_UTF8
*/

#include <LCDI2C_Viet.h>
#include <ROM_Standard_JP.h>

LiquidCrystal_I2C_Viet lcd(0x27, 20, 4);  // I2C address: 0x27; Display size: 20x4

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.println("Bộ đội gặp bợm!");
  lcd.println("Chập choạng, một bợm");
  lcd.println("nhậu nhậu chục xị rượu Ngọc Lợn.");
  delay(4000); lcd.clear();

  lcd.print("Bợm nọ khệnh khạng");
  lcd.println("dựa cột điện, gặp");
  lcd.println("chị bộ đội tại địa phận chạy lại.");
  delay(4000); lcd.clear();

  lcd.print("Chị bộ đội đội chục");
  lcd.println("hột vịt lộn thật nặng nhọc.");
  delay(4000); lcd.clear();

  lcd.println("Bợm gặp mặt chị đẹp");
  lcd.println("tuyệt, định chặn chị");
  lcd.println("bộ đội lại \"bậy bạ\".");
  delay(4000); lcd.clear();

  lcd.println("Chị sợ, chạy gọi cụ");
  lcd.println("thợ điện cạnh bệnh viện.");
}

void loop() {}