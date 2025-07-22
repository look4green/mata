#include "Icon.h"
#include "Display.h"

// 📡 WiFi icon (8x8)
const uint8_t icon_wifi[8] PROGMEM = {
  B00011000,
  B00100100,
  B01000010,
  B10000001,
  B00000000,
  B00011000,
  B00011000,
  B00000000
};

// ⚠️ Warning icon (triangle)
const uint8_t icon_warning[8] PROGMEM = {
  B00011000,
  B00111100,
  B01111110,
  B11111111,
  B11111111,
  B00011000,
  B00011000,
  B00000000
};

// 🛰️ GPS plugin logo (16x16)
const uint8_t plugin_gps[16] PROGMEM = {
  // Add actual bitmap pattern here later
};

// 📡 IR plugin logo (16x16)
const uint8_t plugin_ir[16] PROGMEM = {
  // Add actual bitmap pattern here later
};

// 🧬 Splash logo (e.g., minimal MATA emblem)
const uint8_t mata_logo[128] PROGMEM = {
  // Add full bitmap data — can be logo, monogram, waveform
};

// 📦 Render utility
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
