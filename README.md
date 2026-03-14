# EEPROM Page Write using I2C (AT24C08)

A simple, user-friendly demo that shows how to read and write data to an AT24C08 EEPROM using I2C on an LPC21xx microcontroller. The example verifies operations with two LEDs: green = success, red = failure.

What this project does
- Demonstrates page write and random read operations on an AT24C08 EEPROM.
- Verifies write/read results using LEDs: green for success and red for failure.

Hardware required
- LPC21xx microcontroller board (or compatible ARM microcontroller)
- AT24C08 EEPROM (8 Kbit I2C EEPROM)
- Two LEDs (green and red) + current-limiting resistors
- Pull-up resistors for SDA and SCL (typically 4.7k	3.3k)
- Wiring wires and power supply (VCC and GND)

Typical wiring (example)
- AT24C08 VCC -> 3.3V (or 5V depending on your module)
- AT24C08 GND -> GND
- AT24C08 SDA -> MCU SDA (with pull-up)
- AT24C08 SCL -> MCU SCL (with pull-up)
- Green LED -> MCU GPIO (indicates success)
- Red LED -> MCU GPIO (indicates failure)

Notes about the EEPROM
- Model: AT24C08 (8 Kbit = 1024 bytes)
- Page size: 16 bytes (writes should be aligned to page boundaries for page-write operations)
- Supports standard I2C addressing and protocols

How to use
1. Configure the I2C pins and clock in your LPC21xx project as shown in the source code.
2. Build and flash the firmware to your board (use your toolchain / programmer for LPC21xx).
3. Run the demo: it writes a test page to the EEPROM, reads it back, and lights the green LED on success or red LED on failure.
