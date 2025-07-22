#include "Touchscreen.h"
#include <XPT2046_Touchscreen.h>
#include <SPI.h>

// MATA Touchscreen Handling
// Default wiring pins — adjust as needed for your board
#define TOUCH_CS_PIN 21
#define TOUCH_IRQ_PIN 22

XPT2046_Touchscreen ts(TOUCH_CS_PIN, TOUCH_IRQ_PIN);
TS_Point lastTouch;
unsigned long lastTouchTime = 0;
bool tapped = false;

void initTouchscreen() {
  SPI.begin();
  ts.begin();
  ts.setRotation(1);  // Adjust rotation for correct orientation
}

void updateTouch() {
  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    if (millis() - lastTouchTime > 150) {  // Basic debounce
      lastTouch = p;
      tapped = true;
      lastTouchTime = millis();
    }
  } else {
    tapped = false;
  }
}

bool isTouched() {
  return ts.touched();
}

int getTouchX() {
  return lastTouch.x;
}

int getTouchY() {
  return lastTouch.y;
}

bool touchClicked() {
  if (tapped) {
    tapped = false;      // Reset flag after detection
    return true;
  }
  return false;
}
