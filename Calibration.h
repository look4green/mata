#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <Arduino.h>

// Screen zone detection helpers for MATA touchscreen
// Used for menus, directional taps, and calibration overlays

int getTouchZone(int x, int y);   // Identify screen region from touch point
void showCalibration();           // Display visual zones for testing

#endif
