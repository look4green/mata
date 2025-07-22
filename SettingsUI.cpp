#include "SettingsUI.h"
#include "Display.h"
#include "Encoder.h"
#include "Touchscreen.h"
#include "Settings.h"
#include "ThemeManager.h"

const int settingCount = 3;
String settingLabels[settingCount] = {
  "Theme",
  "Boot Profile",
  "Save & Exit"
};

int settingIndex = 0;

void initSettingsPanel() {
  settingIndex = 0;
}

void drawSettingItem(const String& label, int y, bool highlighted) {
  Theme theme = getCurrentTheme();
  if (highlighted) {
    tft.setTextColor(theme.highlightColor, theme.backgroundColor);
  } else {
    tft.setTextColor(theme.textColor, theme.backgroundColor);
  }

  tft.setTextFont(theme.textFont);
  tft.setCursor(20, y);
  tft.print(label);
}

void updateSettingsPanel() {
  clearScreen();
  drawTitleBar("Settings");

  for (int i = 0; i < settingCount; i++) {
    int y = 50 + i * 30;
    drawSettingItem(settingLabels[i], y, i == settingIndex);
  }

  if (encoderMoved()) {
    if (encoderDirection() > 0) settingIndex = (settingIndex + 1) % settingCount;
    else settingIndex = (settingIndex - 1 + settingCount) % settingCount;
    delay(150);
  }

  if (encoderClicked() || touchClicked()) {
    switch (settingIndex) {
      case 0: {
        // Toggle theme
        String current = getThemeName();
        String next = (current == "dark.json") ? "light.json" : "dark.json";
        setThemeName(next);
        loadTheme(next);
        drawStatus("Theme: " + next);
        break;
      }
      case 1: {
        // Toggle boot profile
        String current = getBootProfile();
        String next = (current == "default.json") ? "aggressive.json" : "default.json";
        setBootProfile(next);
        drawStatus("Profile: " + next);
        break;
      }
      case 2: {
        saveSettings();
        setAppState(STATUS_SCREEN);
        break;
      }
    }
  }
}
