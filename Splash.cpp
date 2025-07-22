#include "Splash.h"
#include "Display.h"
#include "Icon.h"

void showSplash() {
  clearScreen();

  // 🧬 Show MATA logo from Icon.h
  drawIcon(mata_logo, 80, 50, 32, 16, TFT_CYAN);
  drawTitleBar("MATA Toolkit");
  
  tft.setTextFont(2);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setCursor(20, 120);
  tft.println("Modular Attack Toolkit");
  tft.setCursor(20, 140);
  tft.println("v1.0.0 booting...");

  delay(2000);  // Hold splash
}
