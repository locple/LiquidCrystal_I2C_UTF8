#include <LCDI2C_Viet.h>
#include <ROM_Standard_JP.h>

LiquidCrystal_I2C_Viet lcd(0x27, 16, 2);  // LCD1602A

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