#include "ThemeManager.h"
#include <ArduinoJson.h>
#include <SD.h>

// Default theme used on boot or if SD fails
Theme currentTheme = {
  TFT_WHITE,    // highlightColor
  TFT_BLACK,    // backgroundColor
  TFT_GREEN,    // textColor
  2,            // textFont
  30            // spacingY between menu items
};

void loadTheme(const String& themeFile) {
  File file = SD.open("/themes/" + themeFile);
  if (!file) {
    Serial.println("⚠️ Failed to load theme: " + themeFile);
    return;
  }

  StaticJsonDocument<256> doc;
  DeserializationError error = deserializeJson(doc, file);
  file.close();

  if (error) {
    Serial.println("⚠️ Theme JSON parse error");
    return;
  }

  // Override defaults from JSON config
  currentTheme.highlightColor = doc["highlightColor"] | TFT_WHITE;
  currentTheme.backgroundColor = doc["backgroundColor"] | TFT_BLACK;
  currentTheme.textColor      = doc["textColor"]      | TFT_GREEN;
  currentTheme.textFont       = doc["textFont"]       | 2;
  currentTheme.spacingY       = doc["spacingY"]       | 30;
}

Theme getCurrentTheme() {
  return currentTheme;
}
