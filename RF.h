#ifndef RF_H
#define RF_H

#include <Arduino.h>

// Signal output control for MATA
// Handles replay, jamming, and deauth attack logic

void launchDeauth();     // Start deauth packets via NRF
void startJammer();      // Begin jamming mode
void replaySignal();     // Play back a recorded RF signal
void setNRFFrequency(int channel);  // Set channel/frequency for transmission

#endif
