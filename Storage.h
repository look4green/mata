#ifndef STORAGE_H
#define STORAGE_H

#include <Arduino.h>

// SD card interaction for MATA firmware
// Profile loading, logging, and file management

bool initStorage();                         // Mount SD card
bool loadProfile(const String& filename);   // Load attack profile
void listFiles(const String& folder);       // Optional: show folder contents
void logEvent(const String& data);          // Log data to file (events, signals)

#endif
