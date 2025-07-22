#include "Display.h"
#include "ThemeManager.h"
#include <TFT_eSPI.h>

// TFT instance from TFT_eSPI library
TFT_eSPI tft = TFT_eSPI();

// Display initialization
void initDisplay() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  // Optional: Show MATA in corner during boot
  tft.setTextFont(2);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setCursor(180, 220);
  tft.print("MATA");
}

// Clears screen and sets default background
void clearScreen() {
  Theme theme = getCurrentTheme();
  tft.fillScreen(theme.backgroundColor);
}

// Shows a status message mid-screen
void drawStatus(const String& message) {
  Theme theme = getCurrentTheme();
  tft.setTextColor(theme.textColor, theme.backgroundColor);
  tft.setTextFont(theme.textFont);
  tft.setCursor(20, 120);
  tft.print(message);
}

// Horizontal bar-style WiFi RSSI meter
void drawRSSIBars(int rssi) {
  int barLength = map(rssi, -100, -30, 0, 220);
  barLength = constrain(barLength, 0, 220);

  tft.fillRect(10, 200, 220, 10, TFT_DARKGREY);    // Background bar
  tft.fillRect(10, 200, barLength, 10, TFT_GREEN); // Signal level

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextFont(2);
  tft.setCursor(10, 185);
  tft.print("WiFi RSSI: " + String(rssi) + " dBm");
}

// Touch ripple effect (simple animated circle)
void drawRipple(int x, int y, uint16_t color) {
  for (int r = 2; r < 15; r += 2) {
    tft.drawCircle(x, y, r, color);
    delay(15);
  }
}

// Top banner showing MATA identity and current screen title
void drawTitleBar(const char* title) {
  tft.fillRect(0, 0, 240, 20, TFT_DARKGRAY);

  tft.setTextColor(TFT_WHITE, TFT_DARKGRAY);
  tft.setTextFont(2);

  // Left side: MATA branding
  tft.setCursor(10, 4);
  tft.print("MATA");

  // Right side: current screen title
  int labelWidth = tft.textWidth(title);
  tft.setCursor(230 - labelWidth, 4);
  tft.print(title);
}
