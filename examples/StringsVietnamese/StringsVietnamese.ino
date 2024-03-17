#include <LCDI2C_Viet.h>
#include <ROM_Standard_JP.h>

LiquidCrystal_I2C_Viet lcd(0x27, 20, 4);   // LCD2004A

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