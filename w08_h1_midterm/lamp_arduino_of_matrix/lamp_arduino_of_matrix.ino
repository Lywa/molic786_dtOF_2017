#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_BRG + NEO_KHZ800);

char val; // Data received from the serial port

void setup() {

  Serial.begin(9600); // Start serial communication at 9600 bps

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
}

void loop() {
  int serial_count = 0;
  int pos = 0;
  int r = 0;
  int g = 0;
  int b = 0;


  while (Serial.available()) { // If data is available to read,
    val = Serial.read(); // read it and store it in val
    Serial.write(val);  // send back the received value
    /* 
    1 pos 123 125 126
    1 pos 45 76 126
    */

    if (val == 255) {
      serial_count = 0;
    }
    else {
      switch (serial_count) {
        case 1: 
          pos = val;
        case 2:
          r = val;
          break;
        case 3:
          g = val;
          break;
        case 4:
          b = val;
          break;
      }
    }
    if (serial_count == 4) {
 
      strip.setPixelColor(pos, r, g, b);
    }
    serial_count++;
  }
  delay(100); // Wait 100 milliseconds for next reading
}


