#include "Splash.h"
#include "Display.h"

void showSplash() {
  // Clear screen and prepare for splash visuals
  clearScreen();

  // Set main branding font
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextFont(4);
  tft.setCursor(40, 80);
  tft.print("MATA");  // 💡 New identity

  // Subtitle with meaning
  tft.setTextFont(2);
  tft.setCursor(40, 120);
  tft.print("Modular Adaptive Tactical Array");

  // Optional loading animation or pause
  delay(1500);  // Display splash for 1.5s
}
