# LiquidCrystal_I2C_UTF8
An Arduino library extended from LiquidCrystal_I2C to print Vietnamese, Russian, or specific symbols (in UTF-8) to LCDs like LCD1602A, LCD2004A.

## Hardware Required
*Similar to LiquidCrystal_I2C*
- **LCD** (1602, 2004, ...) using controllers:
  Hitachi HD44780U, Wuxi AIP31066, Samsung KS0066, Jewel SPLC780, Sitronix ST7066, Surenoo SLC...
- **I2C adapter**: PCF8574 family. *For convenience, you can buy LCDs with I2C adapter soldered instead doing it yourself.*
- **MCU dev board**: Arduino /Uno/Mini/Nano/Micro, ESP8266, ESP32, WeMos LOLIN D1 Mini, WeMos LOLIN D32, ...

## I2C Wiring
*Similar to LiquidCrystal_I2C*
- For LCD 1601, 1602, 2004: Solder or connect I2C's 1x16 pins to LCD's 1x16 pins

  For LCD 0802, 2002, 4002: Solder or connect I2C's 2x8 pins to LCD's 2x8 pins
- Connect I2C's GND pin to MCU's GND pin
- Connect I2C's VCC pin to MCU's VIN pin
- Connect I2C's **SCL** pin to MCU's SCL pin (*see table below for pin location*)
- Connect I2C's **SDA** pin to MCU's SDA pin (*see table below for pin location*)

|    Pin  | Arduino Uno/Mini/Nano | Arduino Micro | LOLIN D1 Mini | ESP8266 | LOLIN D32 | ESP32 |
|:-------:|:---------------------:|:-------------:|:-------------:|:-------:|:-----:|:-----:|
| **SCL** |           A5          |       3       |        5      |   D1    |  22   |  D22  |
| **SDA** |           A4          |       2       |        4      |   D2    |  21   |  D21  |

## Determine Display Size
|  LCD  | 0801 | 0802 | 1601 | 1602 | 1604 | 2002 | 2004 | 2402 | 4002 | 4004 |
|:-----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|Columns|   8  |   8  |  16  |  16  |  16  |  20  |  20  |  24  |  40  |  40  |
|  Rows |   1  |   2  |   1  |   2  |   4  |   2  |   4  |   2  |   2  |   4  |

## Determine I2C Address
For I2C PCF8574 using **TI** (Texas Instruments) chip: *(most likely **0x27**)*

![I2C TI PCF8574](https://lastminuteengineers.com/wp-content/uploads/arduino/I2C-LCD-Address-Selection-Jumper-Table-for-TI.png)

For I2C PCF8574 using **NXP** chip: *(most likely **0x3F**)*

![I2C NXP PCF8574](https://lastminuteengineers.com/wp-content/uploads/arduino/I2C-LCD-Address-Selection-Jumper-Table-for-NXP.png)

Otherwise, use I2C scanning program to detect I2C address:
https://learn.adafruit.com/scanning-i2c-addresses/arduino

## Demo: print Vietnamese UTF-8 string
```C++
#include <LCDI2C_Viet.h>
#include <ROM_Standard_JP.h>

LiquidCrystal_I2C_Viet lcd(0x27, 20, 4);  // I2C address: 0x27; Display size: 20x4

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Cao đẳng Công thương Việt Nam");
}
void loop() {}
```

## Programming Steps *(see more details in examples folder)*
### Printing English
- Include **`LCDI2C_UTF8.h`** for the main base class and one customized character (°)
> :point_right: Degree (°) symbol can be printed.
- Include **`ROM_Standard_JP.h`** for Greek symbol mappings, only used on LCD with controller chips:

  **HD44780UA00, AIP31066, KS0066F00, KS0066F04, SPLC780D, ST7066-0A**
> :point_right: All English letters, sign (**÷ √ ∞ → ←**), Greek (**Σ Ω α β δ ε θ μ π ρ**), currency (**¥**) symbols can be printed.
- Create LiquidCrystal_I2C_UTF8 object with I2C address, LCD columns, LCD rows
- `init()`: Initialize the LCD
- `backlight()`: Turn on the LCD backlight
- `print(text)`: print UTF-8 text (String or char[]) to LCD
> If no room in current line for the next word, it'll be printed in the next line.
- `print(text, nsec)`: print long text with **nsec** seconds paused
> If no room in the screen to print more, wait **nsec** seconds for audiences to read before clearing to print the next part.

### Printing Vietnamese
- Include **`LCDI2C_Viet.h`** for the main class and customized characters for Vietnamese
> :point_right: All Vietnamese letters and degree (°) symbol can be printed.
- Include **`ROM_Standard_JP.h`** for Greek symbol mappings, only used on LCD with controller chips:

  **HD44780UA00, AIP31066, KS0066F00, KS0066F04, SPLC780D, ST7066-0A**
> :point_right: All English letters, sign (**÷ √ ∞ → ←**), Greek (**Σ Ω α β δ ε θ μ π ρ**), currency (**¥**) symbols can be printed.
- Create LiquidCrystal_I2C_UTF8 object with I2C address, LCD columns, LCD rows
- `init()`: Initialize the LCD
- `backlight()`: Turn on the LCD backlight
- `print(text)`: print UTF-8 text (String or char[]) to LCD
> If no room in current line for the next word, it'll be printed in the next line.
- `print(text, nsec)`: print long text with **nsec** seconds paused
> If no room in the screen to print more, wait **nsec** seconds for audiences to read before clearing to print the next part.

> [!CAUTION]
> Due to CGRAM limit, maximum of 8 Vietnamese letters with diacritics can be printed on a screen, otherwise diacritics removed.
> It's usually enough to print full Vietnamese text on LCD0801, LCD0802, LCD1602.

### Printing Russian
- Include **`LCDI2C_UTF8.h`** for the main base class and one customized character (°)
> :point_right: Degree(°) symbol can be printed.
- Include **`ROM_Surenoo_RU.h`** for Russian letter mappings, only used on LCDs:

  **Russian version of Surenoo SLC series**
> :point_right: All Russian and English letters, arrow (**↵ ↑ → ↓ ←**), currency (**¢ £**), (**×**) symbols can be printed.
- Create LiquidCrystal_I2C_UTF8 object with I2C address, LCD columns, LCD rows
- `init()`: Initialize the LCD
- `backlight()`: Turn on the LCD backlight
- `print(text)`: print UTF-8 text (String or char[]) to LCD
> If no room in current line for the next word, it'll be printed in the next line.
- `print(text, nsec)`: print long text with **nsec** seconds paused
> If no room in the screen to print more, wait **nsec** seconds for audiences to read before clearing to print the next part.

> [!NOTE]
> **Not yet supported**:
> - Autoscroll
> - Printing Japanese Kana on LCDs with Japanese standard ROM!!
