#include <LCDI2C_UTF8.h>
#include <ROM_Standard_RU.h>

LiquidCrystal_I2C_UTF8 lcd(0x27, 16, 2);   // LCD1602A

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