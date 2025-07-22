#ifndef TOUCHSCREEN_H
#define TOUCHSCREEN_H

#include <Arduino.h>

// Touchscreen input API for MATA
// Provides polling, one-shot tap detection, and coordinate readout

void initTouchscreen();       // Initialize hardware
void updateTouch();           // Refresh touch state
bool isTouched();             // Raw touch status
bool touchClicked();          // One-time tap detection
int getTouchX();              // X coordinate of last touch
int getTouchY();              // Y coordinate of last touch

#endif
