## ❓ What if you want to use my code

You must have: 
1. Visual Studio Code [Visual Studio Code Link](https://code.visualstudio.com/) 
2. Platformio [Platformio Link](https://platformio.org/)
3. Adafruit ST7735 and ST7789 Library. Open Visual Studio Code with Platformio installed, go to the Platformio tab -> Libraries -> enter "Adafruit ST7735 and ST7789 Library" and install them.
4. **ESP-32** or other board. If you don't have an ESP-32 go to Platformio -> Boards -> find your board, copy its name, and paste it in the *platformio.ini* file.
5. TFT Display
6. Joystick Module

# Connecting modules to ESP-32
**TFT Display** -> **ESP-32**
> LED -> 3V3
> SCK -> D18
> SDA -> D23
> A0 -> D15
> RESET -> D4
> CS -> D5
> GND -> GND
> VCC -> 3V3

**Joystick** -> **Arduino**
>GND -> GND
>+5V -> VIN
>VRX -> D34
>VRY -> D35
>SW -> D2 (not necessary)

I wrote the code myself, without AI. I'd love to hear feedback. Good luck. ✨
