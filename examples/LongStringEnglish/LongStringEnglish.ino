#include <LCDI2C_UTF8.h>
#include <ROM_Standard_EU.h>

LiquidCrystal_I2C_UTF8 lcd(0x27, 20, 4);   // LCD2004A

void setup() {
  lcd.init();
	lcd.backlight();

  lcd.print("Ernest Miller Hemingway was born in Chicago in 1899 as the son of a doctor and the second of six children. After a stint as an ambulance driver at the Italian front, Hemingway came home to America in 1919, only to return to the battlefield - this time as a reporter on the Greco-Turkish war - in 1922. Resigning from journalism to focus on his writing instead, he moved to Paris where he renewed his earlier friendship with fellow American expatriates such as Ezra Pound and Gertrude Stein. Through the years, Hemingway travelled widely and wrote avidly, becoming an internationally recognized literary master of his craft. He received the Nobel Prize for Literature in 1954, following the publication of The Old Man and the Sea.", 4);
  lcd.println();
  lcd.println("He died in 1961.", 1);

  lcd.setCursor(9, 2); lcd.print("°");
  lcd.write('*'); lcd.setCursor(11, 2); lcd.println("°");
  lcd.println("(https://amazon.com)");
}

void loop() {}