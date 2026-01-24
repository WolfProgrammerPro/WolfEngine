## ❓ What if you want to use my code

You must have: 
1. Visual Studio Code [Visual Studio Code Link](https://code.visualstudio.com/) 
2. Platformio [Platformio Link](https://platformio.org/)
3. Adafruit ST7735 and ST7789 Library. Open Visual Studio Code with Platformio installed, go to the Platformio tab -> Libraries -> enter "Adafruit ST7735 and ST7789 Library" and install them.
4. **Arduino Nano** or other Arduino board. If you don't have an Arduino Nano go to Platformio -> Boards -> find your board, copy its name, and paste it in place of *"nanoatmega328new"* in the *platformio.ini* file.
5. TFT Display
6. Joystick Module

# Connecting modules to Arduino Nano
**TFT Display** -> **Arduino**
> LED -> 3.3V
> SCK -> D13
> SDA -> D11
> A0 -> 9
> RESET -> D8
> CS -> D10
> GND -> GND
> VCC -> 5V

**Joystick** -> **Arduino**
>GND -> GND
>+5V -> 5V
>VRX -> A0
>VRY -> A1
>SW -> D2 (not necessary)

I wrote the code myself, without AI. I'd love to hear feedback. Good luck. ✨
