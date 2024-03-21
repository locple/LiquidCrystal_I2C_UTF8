/*
  Demo: print sample temperature and humidity value to
  a popular LCD1602A (Japanese ROM) using I2C (PCF8574)
  Author: Le Phuoc Loc <phuocloc@gmail.com>

  Note:
  - Include LCDI2C_Viet.h for the main class and customized characters for Vietnamese
    => All Vietnamese letters and degree (°) symbol can be printed.
  - Include ROM_Standard_JP.h for Greek symbol mappings on LCD1602A Japanese ROM
    => All English letters, sign(÷√∞→←), Greek(ΣΩαβδεθμπρ), currency(¥) symbols can be printed.

  https://github.com/locple/LiquidCrystal_I2C_UTF8
*/

#include <LCDI2C_Viet.h>
#include <ROM_Standard_JP.h>

LiquidCrystal_I2C_Viet lcd(0x27, 16, 2);  // I2C address: 0x27; Display size: 16x2

void setup() {
  lcd.init();
  lcd.backlight();

  float temp = 25.78;
  float humi = 9.431;
  char buff[7];
  sprintf(buff, "%.1f", temp);
  lcd.print("Nhiệt độ: "); lcd.print(buff); lcd.println("°C");
  lcd.println("Độ ẩm β:   " + String(humi, 2) + '%');
}

void loop() {}
