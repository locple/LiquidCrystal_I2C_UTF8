# LiquidCrystal_I2C_UTF8
An Arduino library extended from LiquidCrystal_I2C to print Vietnamese, Russian, or specific symbols (in UTF-8) to LCDs like LCD1602A, LCD2004A.

## Hardware Required
*Similar to LiquidCrystal_I2C*
- **MCU dev board**: Arduino /Uno/Mini/Nano/Micro, ESP8266, ESP32, WeMos LOLIN D1 Mini, WeMos LOLIN D32, ...
- **LCD** (1602, 2004, ...) using controller:
  Hitachi HD44780U, Wuxi AIP31066, Samsung KS0066, Jewel SPLC780D, Sitronix ST7066

  *For convenience, you can buy LCD with an I2C adapter soldered instead doing it yourself.*
- **I2C adapter** using PCF8574 chip having 1x16-pin or 2x8-pin interface to LCD.

  *Refer to table below (for Surenoo LCD series) to find the right I2C adapter:*

|   LCD  | 0801 | 0802 | 1601 | 1602 | 1604 | 2002 | 2004 | 2402 | 4002 | 4004 |
|:------:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|Pin type|2x7 +2|  2x8 | 1x16 | 1x16 | 1x16 | 2x8  | 1x16 |  2x8 |  2x8 |  2x8 |

## I2C Wiring
*Similar to LiquidCrystal_I2C*
- Solder or connect I2C's 1x16 (or 2x8) pins to LCD's 1x16 (or 2x8) pins
- Connect I2C's GND pin to MCU's GND pin
- Connect I2C's VCC pin to MCU's VIN pin
- Connect I2C's **SCL** pin to MCU's SCL pin (*see table below for pin location*)
- Connect I2C's **SDA** pin to MCU's SDA pin (*see table below for pin location*)

|    Pin  | Arduino Uno/Mini/Nano | Arduino Micro | LOLIN D1 Mini | ESP8266 | LOLIN D32 | ESP32 |
|:-------:|:---------------------:|:-------------:|:-------------:|:-------:|:-----:|:-----:|
| **SCL** |           A5          |       3       |        5      |   D1    |  22   |  D22  |
| **SDA** |           A4          |       2       |        4      |   D2    |  21   |  D21  |

## Find Display Size
|  LCD  | 0801 | 0802 | 1601 | 1602 | 1604 | 2002 | 2004 | 2402 | 4002 | 4004 |
|:-----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|columns|   8  |   8  |  16  |  16  |  16  |  20  |  20  |  24  |  40  |  40  |
|  rows |   1  |   2  |   1  |   2  |   4  |   2  |   4  |   2  |   2  |   4  |

## Find I2C Address
For I2C PCF8574 using **TI** (Texas Instruments) chip: *(most likely **0x27**)*

![I2C TI PCF8574](https://lastminuteengineers.com/wp-content/uploads/arduino/I2C-LCD-Address-Selection-Jumper-Table-for-TI.png)

For I2C PCF8574 using **NXP** chip: *(most likely **0x3F**)*

![I2C NXP PCF8574](https://lastminuteengineers.com/wp-content/uploads/arduino/I2C-LCD-Address-Selection-Jumper-Table-for-NXP.png)

Otherwise, use I2C scanning program to detect I2C address:
https://learn.adafruit.com/scanning-i2c-addresses/arduino

## Write Demo: print a Vietnamese string
```C++
#include <LCDI2C_Viet.h>                  // Main class and Vietnamese customized characters
#include <ROM_Standard_JP.h>              // Character mapping for most popular LCDs (Japanese ROM)

LiquidCrystal_I2C_Viet lcd(0x27, 16, 2);  // I2C address = 0x27; Display columns = 16, rows = 2

void setup() {
  lcd.init();                             // Initialize the LCD
  lcd.backlight();                        // Turn on the LCD backlight
  lcd.print("Cao đẳng Công thương Việt Nam");
}
void loop() {}
```

## Write Demo: print a long Russian string
```C++
#include <LCDI2C_UTF8.h>                  // Main class
#include <ROM_Surenoo_RU.h>               // Character mapping for Surenoo LCDs (Russian ROM)

LiquidCrystal_I2C_UTF8 lcd(0x27, 20, 2);  // I2C address = 0x27; Display columns = 20, rows = 2

void setup() {
  lcd.init();                             // Initialize the LCD
  lcd.backlight();                        // Turn on the LCD backlight
  lcd.print("Подмосковные вечера — одна из самых популярных советских песен, её исполняли \
известные эстрадные и академические певцы, хоры и оркестры в СССР и за рубежом.", 3);
}
void loop() {}
```
*See more demos in examples folder*

## What header files to include
### Printing English
- Include **`LCDI2C_UTF8.h`** for the main base class and one customized character (°)
> :point_right: Degree (°) symbol can be printed.
- Include **`ROM_Standard_JP.h`** for Greek symbol mappings, only used on LCD with controller chips:

  **HD44780UA00, AIP31066, KS0066F00, KS0066F04, SPLC780D, ST7066-0A**
> :point_right: All English letters, sign (**÷ √ ∞ → ←**), Greek (**Σ Ω α β δ ε θ μ π ρ**), currency (**¥**) symbols can be printed.

### Printing Vietnamese
- Include **`LCDI2C_Viet.h`** for the main class and customized characters for Vietnamese
> :point_right: All Vietnamese letters and degree (°) symbol can be printed.
- Include **`ROM_Standard_JP.h`** for Greek symbol mappings, only used on LCD with controller chips:

  **HD44780UA00, AIP31066, KS0066F00, KS0066F04, SPLC780D, ST7066-0A**
> :point_right: All English letters, sign (**÷ √ ∞ → ←**), Greek (**Σ Ω α β δ ε θ μ π ρ**), currency (**¥**) symbols can be printed.

> [!CAUTION]
> Due to CGRAM limit, maximum of 8 Vietnamese letters with diacritics can be printed on a screen, otherwise diacritics removed.
> It's usually enough to print full Vietnamese text on LCD0801, LCD0802, LCD1602.

### Printing Russian
- Include **`LCDI2C_UTF8.h`** for the main base class and one customized character (°)
> :point_right: Degree(°) symbol can be printed.
- Include **`ROM_Surenoo_RU.h`** for Russian letter mappings, only used on LCDs:

  **Russian version of Surenoo SLC series**
> :point_right: All Russian and English letters, arrow (**↵ ↑ → ↓ ←**), currency (**¢ £**), (**×**) symbols can be printed.

## Function print()
- `print(text)`: print UTF-8 text (String or char[]) to LCD
> If no room in current line for the next word, it'll be printed in the next line.
- `print(text, nsec)`: print long text with **nsec** seconds paused
> If no room in the screen to print more, wait **nsec** seconds for audiences to read before clearing to print the next part.

> [!NOTE]
> **Not yet supported**:
> - Autoscroll
> - Printing Japanese Kana on LCDs with Japanese standard ROM!!
