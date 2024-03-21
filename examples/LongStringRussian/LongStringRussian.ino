/*
  LongStringRussian: print a long Russian text to
  a Surenoo SLC1602 LCD (Russian ROM) using I2C (PCF8574)
  Author: Le Phuoc Loc <phuocloc@gmail.com>

  Note:
  - Include LCDI2C_UTF8.h for the main base class and one customized character (°):
    => Degree (°) symbol can be printed.
  - Include ROM_Surenoo_RU.h for Russian letter mappings on Surenoo SLC1602 (Russian)
    => All Russian and English letters, arrow (↵↑→↓←), currency (¢£), (×) symbols can be printed.
  - If no longer room to print the next word in current line, it'll be printed in next line.
  - print(text, nsec): print long text with pause 'nsec' seconds
    If the screen is full, wait 'nsec' seconds for audience to read before printing the next part on next screen.

  https://github.com/locple/LiquidCrystal_I2C_UTF8
*/

#include <LCDI2C_UTF8.h>
#include <ROM_Surenoo_RU.h>

LiquidCrystal_I2C_UTF8 lcd(0x27, 16, 2);  // I2C address: 0x27; Display size: 16x2

void setup() {
  lcd.init();
  lcd.backlight();

  // Print long text with pause (in seconds): if no room left on screen to print,
  // delay a given time (= 4s) before clearing screen and printing the next part
  lcd.println("Расцветали яблони и груши, Поплыли туманы над рекой.\
 Выходила на берег Катюша, На высокий берег на крутой.\
 Выходила, песню заводила, Про степного, сизого орла,\
 Про того, которого любила, Про того, чьи письма берегла.\
 Ой ты, песня, песенка девичья, Ты лети за ясным солнцем вслед.\
 И бойцу на дальнем пограничье, От Катюши передай привет.\
 Пусть он вспомнит девушку простую, Пусть услышит, как она поет,\
 Пусть он землю бережет родную, А любовь Катюша сбережет.", 4);
}

void loop() {}
