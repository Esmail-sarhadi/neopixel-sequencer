/********************************************************************************************************
  neopixel_sequencer:
  Modified by Esmail-sarhadi
  
  This sketch will show multiple lighting patterns for NeoPixel strip.
  The patterns will switch automatically.
  
---------------------------------------------------------------------------------------------------------
NeoPixel Information for initializing the strip, below
  60ma/pixel for current load
  Parameter 1 = number of pixels in strip
  Parameter 2 = pin number (most are valid)
  Parameter 3 = pixel type flags, add together as needed:
    NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
    NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
    NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
    NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

**********************************************************************************************************/

#include <Adafruit_NeoPixel.h>

// the data pin for the NeoPixels
int neoPixelPin = 15;

// How many NeoPixels we will be using
int numPixels = 8;

// Instatiate the NeoPixel from the library
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, neoPixelPin, NEO_GRB + NEO_KHZ800);

// Pattern state
int patternState = 0;
const int numPatterns = 20;

// variable delay time
int delayTime = 100; // 100ms delay by default

unsigned long previousMillis = 0;

// Function prototypes
void patternRainbow();
void patternTheaterChase();
void patternColorWipe(uint32_t color);
void patternScanner(uint32_t color);
void patternFadeInFadeOut(uint32_t color);
void patternStrobe(uint32_t color);
uint32_t Wheel(byte WheelPos);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= delayTime) {
    previousMillis = currentMillis;
    
    switch (patternState) {
      case 0:
        patternRainbow();
        break;
      case 1:
        patternTheaterChase();
        break;
      case 2:
        patternColorWipe(strip.Color(255, 0, 0)); // Red
        break;
      case 3:
        patternColorWipe(strip.Color(0, 255, 0)); // Green
        break;
      case 4:
        patternColorWipe(strip.Color(0, 0, 255)); // Blue
        break;
      case 5:
        patternScanner(strip.Color(255, 0, 0)); // Red
        break;
      case 6:
        patternScanner(strip.Color(0, 255, 0)); // Green
        break;
      case 7:
        patternScanner(strip.Color(0, 0, 255)); // Blue
        break;
      case 8:
        patternFadeInFadeOut(strip.Color(255, 0, 0)); // Red
        break;
      case 9:
        patternFadeInFadeOut(strip.Color(0, 255, 0)); // Green
        break;
      case 10:
        patternFadeInFadeOut(strip.Color(0, 0, 255)); // Blue
        break;
      case 11:
        patternStrobe(strip.Color(255, 0, 0)); // Red
        break;
      case 12:
        patternStrobe(strip.Color(0, 255, 0)); // Green
        break;
      case 13:
        patternStrobe(strip.Color(0, 0, 255)); // Blue
        break;
      case 14:
        patternRainbow();
        break;
      case 15:
        patternTheaterChase();
        break;
      case 16:
        patternColorWipe(strip.Color(255, 255, 0)); // Yellow
        break;
      case 17:
        patternColorWipe(strip.Color(0, 255, 255)); // Cyan
        break;
      case 18:
        patternColorWipe(strip.Color(255, 0, 255)); // Magenta
        break;
      case 19:
        patternScanner(strip.Color(255, 255, 255)); // White
        break;
    }
    
    patternState++;
    if (patternState >= numPatterns) {
      patternState = 0;
    }
  }
}

void patternRainbow() {
  for(int j =0 ; j<250 ; j++){
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i * 256 / strip.numPixels()) & 255));
    }
    strip.show();
    delay(10);
  }
  
}

void patternTheaterChase() {
  for (int j = 0; j < 10; j++) {  // repeat 10 times
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0xFFFFFF);    // turn every third pixel on
      }
      strip.show();

      delay(50);

      for (int i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);        // turn every third pixel off
      }
    }
  }
}

void patternColorWipe(uint32_t color) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(50);
  }
}

void patternScanner(uint32_t color) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(50);
    strip.setPixelColor(i, 0);
  }
  for (int i = strip.numPixels() - 1; i >= 0; i--) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(50);
    strip.setPixelColor(i, 0);
  }
}

void patternFadeInFadeOut(uint32_t color) {
  for (int k = 0; k < 256; k = k + 5) {
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, (color >> 16) * k / 256, (color >> 8 & 0xFF) * k / 256, (color & 0xFF) * k / 256);
    }
    strip.show();
    delay(30);
  }
  for (int k = 255; k >= 0; k = k - 5) {
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, (color >> 16) * k / 256, (color >> 8 & 0xFF) * k / 256, (color & 0xFF) * k / 256);
    }
    strip.show();
    delay(30);
  }
}

void patternStrobe(uint32_t color) {
  for (int j = 0; j < 10; j++) {
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, color);
    }
    strip.show();
    delay(50);
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 0);
    }
    strip.show();
    delay(50);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
