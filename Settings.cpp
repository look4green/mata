#include "Settings.h"
#include <EEPROM.h>
#include "Display.h"

#define EEPROM_SIZE 64
#define BOOT_PROFILE_ADDR 0
#define THEME_NAME_ADDR 32

String bootProfile = "default.json";
String themeName = "dark.json";

void loadSettings() {
  EEPROM.begin(EEPROM_SIZE);
  char bp[32], tn[32];
  for (int i = 0; i < 32; i++) {
    bp[i] = EEPROM.read(BOOT_PROFILE_ADDR + i);
    tn[i] = EEPROM.read(THEME_NAME_ADDR + i);
  }
  bootProfile = String(bp);
  themeName = String(tn);
  EEPROM.end();
}

void saveSettings() {
  EEPROM.begin(EEPROM_SIZE);
  for (int i = 0; i < 32; i++) {
    EEPROM.write(BOOT_PROFILE_ADDR + i, i < bootProfile.length() ? bootProfile[i] : 0);
    EEPROM.write(THEME_NAME_ADDR + i, i < themeName.length() ? themeName[i] : 0);
  }
  EEPROM.commit();
  EEPROM.end();
}

String getBootProfile() {
  return bootProfile;
}

String getThemeName() {
  return themeName;
}

void setBootProfile(const String& name) {
  bootProfile = name;
}

void setThemeName(const String& name) {
  themeName = name;
}
