#include "ProfileSelector.h"
#include "Storage.h"
#include "AppState.h"
#include "Display.h"
#include "Touchscreen.h"
#include <SD.h>

#define MAX_PROFILES 10

String profileNames[MAX_PROFILES];
int profileCount = 0;
int selectedIndex = 0;

void initProfileSelector() {
  profileCount = 0;
  selectedIndex = 0;

  File dir = SD.open("/profiles");
  while (true) {
    File entry = dir.openNextFile();
    if (!entry) break;
    String name = String(entry.name());
    if (name.endsWith(".json") && profileCount < MAX_PROFILES) {
      profileNames[profileCount++] = name;
    }
    entry.close();
  }
  dir.close();
}

void updateProfileSelector() {
  clearScreen();
  drawTitleBar("Select Profile");

  for (int i = 0; i < profileCount; i++) {
    int y = 40 + i * 20;
    if (i == selectedIndex)
      tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    else
      tft.setTextColor(TFT_WHITE, TFT_BLACK);

    tft.setCursor(20, y);
    tft.print(profileNames[i]);
  }

  if (encoderMoved()) {
    if (encoderDirection() > 0) selectedIndex = (selectedIndex + 1) % profileCount;
    else selectedIndex = (selectedIndex - 1 + profileCount) % profileCount;
    delay(150);
  }

  if (encoderClicked() || touchClicked()) {
    loadProfile(profileNames[selectedIndex]);
    setAppState(STATUS_SCREEN);
  }
}
