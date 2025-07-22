#include "Icon.h"
#include "Display.h"

// 🧬 MATA splash logo — 16x8 monogram (example)
const uint8_t mata_logo[128] PROGMEM = {
  B11100111, B00000000, B00011100, B00111000,
  B10000101, B00000000, B00100010, B01000100,
  B11100111, B00000000, B00011100, B01111000,
  B10000101, B00000000, B00100000, B01000100,
  B10000101, B00000000, B00100000, B01000100,
  B10000101, B00000000, B00100000, B01000100,
  B10000101, B00000000, B00100000, B01000100,
  B10000101, B00000000, B00100000, B01111100,
  // ... Fill the rest as needed
};

// 📡 LoRa plugin icon (simplified antenna)
const uint8_t plugin_lora[16] PROGMEM = {
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B11011011,
  B01111110,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00111100,
  B00111100,
  B01111110,
  B11111111,
  B00000000
};

// 📲 Bluetooth icon
const uint8_t plugin_bluetooth[16] PROGMEM = {
  B00000000,
  B00011000,
  B00100100,
  B01001010,
  B10010001,
  B01001010,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B01001010,
  B10010001,
  B01001010,
  B00100100,
  B00011000,
  B00000000
};

// 🛰️ GPS plugin icon
const uint8_t plugin_gps[16] PROGMEM = {
  B00000000,
  B00111000,
  B01111100,
  B11111110,
  B11111110,
  B01111100,
  B00111000,
  B00000000,
  B00001000,
  B00011100,
  B00101010,
  B01000001,
  B01000001,
  B00101010,
  B00011100,
  B00001000
};

// 🔦 IR plugin icon (burst symbol)
const uint8_t plugin_ir[16] PROGMEM = {
  B00000000,
  B01010101,
  B00101010,
  B00011100,
  B00101010,
  B01010101,
  B00000000,
  B00000000,
  B00011000,
  B00111100,
  B01111110,
  B00111100,
  B00011000,
  B00000000,
  B00000000,
  B00000000
};

// 🧬 Renderer reused
void drawIcon(const uint8_t* bitmap, int x, int y, int w, int h, uint16_t color) {
  for (int j = 0; j < h; j++) {
    uint8_t row = pgm_read_byte(bitmap + j);
    for (int i = 0; i < w; i++) {
      if (bitRead(row, 7 - i)) {
        tft.drawPixel(x + i, y + j, color);
      }
    }
  }
}
