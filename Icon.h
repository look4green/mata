#ifndef ICON_H
#define ICON_H

#include <Arduino.h>

// ⚙️ Monochrome 8x8 icons stored in PROGMEM
extern const uint8_t icon_wifi[8];
extern const uint8_t icon_warning[8];
extern const uint8_t plugin_gps[16];
extern const uint8_t plugin_ir[16];
extern const uint8_t mata_logo[128];  // For splash

void drawIcon(const uint8_t* bitmap, int x, int y, int w, int h, uint16_t color);  // Render helper

#endif
