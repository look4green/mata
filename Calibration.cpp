#include "Calibration.h"
#include "Display.h"
#include "Touchscreen.h"

// Zone definitions (example: 3 horizontal bands)
#define ZONE_TOP     1
#define ZONE_MIDDLE  2
#define ZONE_BOTTOM  3

int getTouchZone(int x, int y) {
  if (y < 80)       return ZONE_TOP;
  else if (y < 160) return ZONE_MIDDLE;
  else              return ZONE_BOTTOM;
}

void showCalibration() {
  clearScreen();

  tft.setTextFont(2);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  // Draw zone labels visually
  tft.setCursor(10, 20);
  tft.print("Top Zone");

  tft.setCursor(10, 100);
  tft.print("Middle Zone");

  tft.setCursor(10, 180);
  tft.print("Bottom Zone");

  // Optional: Draw lines to mark zones
  tft.drawLine(0, 80, 240, 80, TFT_DARKGRAY);
  tft.drawLine(0, 160, 240, 160, TFT_DARKGRAY);
}
