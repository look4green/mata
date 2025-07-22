#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>

void loadSettings();                  // Load settings from SD or EEPROM
void saveSettings();                  // Persist current preferences
String getBootProfile();              // Return boot profile name
String getThemeName();                // Return active theme
void setBootProfile(const String& name);
void setThemeName(const String& name);

#endif
