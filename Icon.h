#ifndef ICON_H
#define ICON_H

#include <Arduino.h>

// Core icon sets for MATA GUI
extern const uint8_t mata_logo[128];     // Splash emblem
extern const uint8_t plugin_lora[16];    // LoRa logo
extern const uint8_t plugin_bluetooth[16]; // BT terminal
extern const uint8_t plugin_gps[16];     // GPS overlay
extern const uint8_t plugin_ir[16];      // IR blaster

void drawIcon(const uint8_t* bitmap, int x, int y, int w, int h, uint16_t color);

#endif
