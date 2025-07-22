#include "PowerManager.h"
#include "Display.h"
#include "Touchscreen.h"
#include "Encoder.h"

// MATA Power Management Implementation
// Uses display OFF commands (ILI9341 standard)

#define INACTIVITY_TIMEOUT 30000  // 30 seconds timeout
unsigned long lastInteraction = 0;
bool isDimmed = false;

void initPowerManager() {
  lastInteraction = millis();
  isDimmed = false;
}

void resetInactivityTimer() {
  lastInteraction = millis();
  if (isDimmed) {
    tft.writecommand(0x29);  // Display ON
    isDimmed = false;
    drawStatus("Awake");     // Optional wake message
  }
}

void updatePowerManager() {
  if (encoderMoved() || encoderClicked() || touchClicked()) {
    resetInactivityTimer();  // React to user input
  }

  if (!isDimmed && millis() - lastInteraction > INACTIVITY_TIMEOUT) {
    tft.writecommand(0x28);  // Display OFF
    isDimmed = true;
  }
}
