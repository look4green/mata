#ifndef POWER_MANAGER_H
#define POWER_MANAGER_H

#include <Arduino.h>

// Power manager module for MATA
// Tracks idle time, dims display, and manages wake events

void initPowerManager();         // Initialize timers
void updatePowerManager();       // Called every loop to check dim state
void resetInactivityTimer();     // Call on input to reset sleep timer

#endif
