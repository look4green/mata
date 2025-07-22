#include "Diagnostics.h"
#include "Display.h"
#include <WiFi.h>

// Optional: check if modules like NRF, CC1101, SD are wired correctly
bool checkModuleStatus() {
  bool allGood = true;

  // Example check: SD card
  if (!SD.begin()) {
    drawStatus("SD module error");
    allGood = false;
  }

  // Future: Add checks for NRF, CC1101, encoder
  // drawStatus("NRF OK"); drawStatus("CC1101 Ready");

  return allGood;
}

// Live RSSI visualization
void showSignalStrength() {
  int rssi = WiFi.RSSI();

  drawTitleBar("Signal Check");
  drawRSSIBars(rssi);

  // Optional: log reading
  Serial.println("RSSI: " + String(rssi));
}
