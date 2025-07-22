#include "Menu.h"
#include "Display.h"
#include "AppState.h"
#include "Touchscreen.h"
#include "Encoder.h"
#include "ThemeManager.h"

const int menuSize = 6;
String menuItems[menuSize] = {
  "Status",
  "Sniff Packets",
  "Deauth Attack",
  "Jamming",
  "Replay",
  "Diagnostics"
};

int menuIndex = 0;

void initMenu() {
  menuIndex = 0;
}

int getMenuIndex() {
  return menuIndex;
}

void setMenuIndex(int index) {
  menuIndex = constrain(index, 0, menuSize - 1);
}

void nextMenuItem() {
  menuIndex = (menuIndex + 1) % menuSize;
}

void prevMenuItem() {
  menuIndex = (menuIndex - 1 + menuSize) % menuSize;
}

void selectMenuItem() {
  switch (menuIndex) {
    case 0: setAppState(STATUS_SCREEN);    break;
    case 1: setAppState(PACKET_SNIFF);     break;
    case 2: setAppState(DEAUTH_ATTACK);    break;
    case 3: setAppState(JAM_MODE);         break;
    case 4: setAppState(REPLAY_MODE);      break;
    case 5: setAppState(DIAGNOSTICS);      break;
  }
}

void drawMenuItem(const String& label, int y, bool highlighted) {
  Theme theme = getCurrentTheme();

  int x = 20;
  if (highlighted) {
    tft.setTextColor(theme.highlightColor, theme.backgroundColor);
  } else {
    tft.setTextColor(theme.textColor, theme.backgroundColor);
  }

  tft.setTextFont(theme.textFont);
  tft.setCursor(x, y);
  tft.print(label);
}

void updateMenu() {
  Theme theme = getCurrentTheme();
  clearScreen();
  drawTitleBar("Main Menu");

  for (int i = 0; i < menuSize; i++) {
    int y = 40 + (i * theme.spacingY);
    drawMenuItem(menuItems[i], y, i == menuIndex);
  }

  if (encoderMoved()) {
    if (encoderDirection() > 0) nextMenuItem();
    else prevMenuItem();
    delay(150); // Smooth scroll
  }

  if (encoderClicked() || touchClicked()) {
    selectMenuItem();
    resetInactivityTimer();
  }
}
