# LiquidCrystal_I2C_UTF8
An Arduino library extended from LiquidCrystal_I2C to print Vietnamese/Russian (UTF-8) on LCDs (16x2, 20x4...)

## Hardware Required
- **LCD** (1602, 2004, ...) using controllers/drivers:
  Hitachi HD44780U, Wuxi AIP31066, Samsung KS0066, Jewel Hill SPLC780, Sitronix ST7066, Surenoo SLC series, ...
- **I2C adapter**: PCF8574 family. *For convenience, you can buy LCDs with I2C adapter soldered instead doing it yourself.*
- **MCU dev board**: Arduino /Uno/Mini/Nano/Micro, ESP8266, ESP32, WeMos LOLIN D1 Mini, WeMos LOLIN D32, ...

## I2C Wiring
- Solder or connect 16-pin row to LCD's 16-pin row
- Connect GND pin to MCU's GND pin
- Connect VCC pin to MCU's VIN pin
- Connect **SCL** pin to MCU's SCL pin (refer to MCU pinout diagram)
- Connect **SDA** pin to MCU's SDA pin (refer to MCU pinout diagram)

## Determine Display Size
- LCD**0801** = 08 columns x 01 rows
- LCD**1602** = 16 columns x 02 rows
- LCD**2002** = 20 columns x 02 rows
- LCD**2004** = 20 columns x 04 rows
- LCD**4004** = 40 columns x 04 rows

## Determine I2C Address
- No shortcut on A0, A1, A2 of TI's PCF8574    => I2C Address = **0x27**
- No shortcut on A0, A1, A2 of NXP's PCF8574   => I2C Address = **0x3F**

Otherwise, use I2C scanning program to detect I2C address:
https://learn.adafruit.com/scanning-i2c-addresses/arduino

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
- `print(text)`: print text (String or char[]) to LCD
> If no longer room to print the next word in current line, it'll be printed in next line.
- `print(text, nsec)`: print long text with pause **nsec** seconds
> If the screen is full, wait **nsec** seconds for audience to read before printing the next part on next screen.

### Printing Vietnamese
- Include **`LCDI2C_Viet.h`** for the main class and customized characters for Vietnamese
> :point_right: All Vietnamese letters and degree (°) symbol can be printed.
- Include **`ROM_Standard_JP.h`** for Greek symbol mappings, only used on LCD with controller chips:

  **HD44780UA00, AIP31066, KS0066F00, KS0066F04, SPLC780D, ST7066-0A**
> :point_right: All English letters, sign (**÷ √ ∞ → ←**), Greek (**Σ Ω α β δ ε θ μ π ρ**), currency (**¥**) symbols can be printed.
- Create LiquidCrystal_I2C_UTF8 object with I2C address, LCD columns, LCD rows
- `init()`: Initialize the LCD
- `backlight()`: Turn on the LCD backlight
- `print(text)`: print text (String or char[]) to LCD
> If no longer room to print the next word in current line, it'll be printed in next line.
- `print(text, nsec)`: print long text with pause **nsec** seconds
> If the screen is full, wait **nsec** seconds for audience to read before printing the next part on next screen.

> [!CAUTION]
> Due to CGRAM limit, maximum of 8 Vietnamese letters with diacritics can be printed on a screen, otherwise diacritics removed.
> It's usually enough to print full Vietnamese text on LCD0801, LCD0802, LCD1602.

### Printing Russian
- Include **`LCDI2C_UTF8.h`** for the main base class and one customized character (°)
> :point_right: Degree(°) symbol can be printed.
- Include **`ROM_Surenoo_RU.h`** for Russian letter mappings, only used on LCD with controller chips:

  **Russian version of Surenoo SLC series**
> :point_right: All Russian and English letters, arrow (**↵ ↑ → ↓ ←**), currency (**¢ £**), (**×**) symbols can be printed.
- Create LiquidCrystal_I2C_UTF8 object with I2C address, LCD columns, LCD rows
- `init()`: Initialize the LCD
- `backlight()`: Turn on the LCD backlight
- `print(text)`: print text (String or char[]) to LCD
> If no longer room to print the next word in current line, it'll be printed in next line.
- `print(text, nsec)`: print long text with pause **nsec** seconds
> If the screen is full, wait **nsec** seconds for audience to read before printing the next part on next screen.

> [!NOTE]
> **Not yet supported**:
> - Autoscroll
> - Printing Japanese Kana on LCDs with Japanese standard ROM!!
