/*
  LongStringEnglish: print a long English text to a LCD2004A (EU/Latin ROM) using I2C (PCF8574),
  also call some functions from parent class LiquidCrystal_I2C for demonstrating interoperability.
  Author: Le Phuoc Loc <phuocloc@gmail.com>

  Note:
  - Include LCDI2C_UTF8.h for the main base class and one customized character (°)
    => Degree(°) symbol can be printed.
  - Include ROM_Standard_EU.h for Greek symbol mappings on LCD2004A EU/Latin ROM
    => All English letters, sign(±≈²³×÷≤≥√∞↵↑→↓←), Greek(ΣΩαβγδεηθμπρσψω), currency(¢£¥) symbols can be printed.
  - If no longer room to print the next word in current line, it'll be printed in next line.
  - print(text, nsec): print long text with pause 'nsec' seconds
    If the screen is full, wait 'nsec' seconds for audience to read before printing the next part on next screen.

  https://github.com/locple/LiquidCrystal_I2C_UTF8
*/

#include <LCDI2C_UTF8.h>
#include <ROM_Standard_EU.h>

LiquidCrystal_I2C_UTF8 lcd(0x27, 20, 4);  // I2C address: 0x27; Display size: 20x4

void setup() {
  lcd.init();
  lcd.backlight();

  // Print long text with pause (in seconds): if no room left on screen to print,
  // delay a given time (= 3s) before clearing screen and printing the next part
  lcd.print("Ernest Miller Hemingway was born in Chicago in 1899 as the son of a doctor and the second of six children. After a stint as an ambulance driver at the Italian front, Hemingway came home to America in 1919, only to return to the battlefield - this time as a reporter on the Greco-Turkish war - in 1922. Resigning from journalism to focus on his writing instead, he moved to Paris where he renewed his earlier friendship with fellow American expatriates such as Ezra Pound and Gertrude Stein. Through the years, Hemingway travelled widely and wrote avidly, becoming an internationally recognized literary master of his craft. He received the Nobel Prize for Literature in 1954, following the publication of The Old Man and the Sea.", 3);
  lcd.println();
  lcd.println("He died in 1961.", 1);

  lcd.setCursor(9, 2); lcd.print("°");
  lcd.write('*'); lcd.setCursor(11, 2); lcd.println("∞");
  lcd.println("(https://amazon.com)");
}

void loop() {}
