#ifndef THEME_MANAGER_H
#define THEME_MANAGER_H

#include <Arduino.h>

// Theme config struct for MATA UI personalization
struct Theme {
  uint16_t highlightColor;
  uint16_t backgroundColor;
  uint16_t textColor;
  int textFont;
  int spacingY;
};

void loadTheme(const String& themeFile);  // Load from SD
Theme getCurrentTheme();                  // Retrieve active theme

#endif
