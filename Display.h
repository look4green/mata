#ifndef DISPLAY_H
#define DISPLAY_H

#include <TFT_eSPI.h>

// Global TFT instance declaration
extern TFT_eSPI tft;

// Display initialization
void initDisplay();

// UI element rendering
void drawMenuItem(const char* label, int y, bool selected);
void drawStatus(const char* message);

// Utility
void clearScreen();

#endif // DISPLAY_H
