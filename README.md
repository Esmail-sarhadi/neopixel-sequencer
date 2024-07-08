# neopixel-sequencer
This repository contains a project for controlling NeoPixel LED strips using an Arduino. The code cycles through multiple lighting patterns, automatically switching between them. The NeoPixel strip is initialized with specific parameters and various lighting effects are implemented, including rainbow, theater chase, color wipe, scanner, fade in/out, and strobe. The patterns can be easily modified or expanded upon for customized LED displays.


---

## Features

- **Rainbow Pattern:** Displays a moving rainbow across the strip.
- **Theater Chase:** Creates a theater marquee effect.
- **Color Wipe:** Sequentially lights up each LED in a specified color.
- **Scanner:** Simulates a scanning light effect.
- **Fade In/Out:** Smoothly fades LEDs in and out.
- **Strobe:** Rapidly flashes the LEDs.

## Hardware Required

- Arduino (any model)
- NeoPixel LED strip (WS2812 or similar)
- Connecting wires
- Power supply for the LED strip (ensure it matches the power requirements of your NeoPixel strip)

## Software Required

- Arduino IDE
- Adafruit NeoPixel library

## Installation

1. **Install the Adafruit NeoPixel library:**
   - Open the Arduino IDE.
   - Go to Sketch > Include Library > Manage Libraries...
   - Search for "Adafruit NeoPixel".
   - Click "Install".

2. **Clone this repository:**
   ```bash
   git clone https://github.com/Esmail-sarhadi/neopixel-sequencer.git
   ```

3. **Navigate to the project directory:**
   ```bash
   cd neopixel-sequencer
   ```

4. **Open the project in the Arduino IDE:**
   - Open the `neopixel_sequencer.ino` file from the project directory.

## Usage

1. **Connect the NeoPixel strip to your Arduino:**
   - Data pin is set to pin 15 by default. Modify the `neoPixelPin` variable in the code if needed.
   - Adjust the `numPixels` variable to match the number of LEDs in your strip.

2. **Upload the sketch to your Arduino:**
   - Select the correct board and port in the Arduino IDE.
   - Click "Upload".

3. **Power the NeoPixel strip** with an appropriate power supply.

## Code

You can find the complete code in the `neopixel_sequencer.ino` file included in this repository.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

Feel free to submit issues and pull requests. Contributions are welcome!

---

You can replace `your-username` with your actual GitHub username or the name of your repository.
