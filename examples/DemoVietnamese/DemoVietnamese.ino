#include <LCDI2C_Viet.h>
#include <ROM_Standard_JP.h>

LiquidCrystal_I2C_Viet lcd(0x27, 20, 4);   // LCD2004A

void setup() {
  lcd.init();
	lcd.backlight();

  lcd.println("CAO ĐẲNG CÔNG THƯƠNG VIỆT NAM");
  delay(3000); lcd.clear();
  lcd.print("Cao đẳng Công thương Việt Nam");
}

void loop() {}