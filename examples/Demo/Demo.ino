#include <LCDI2C_Viet.h>
#include <ROM_Surenoo_RU.h>

LiquidCrystal_I2C_Viet lcd(0x27, 16, 2);   // LCD1602A

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.println("Dòng tiếng Việt!");
  lcd.println("Русская надпись!");
}

void loop() {}