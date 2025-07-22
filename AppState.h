#ifndef APPSTATE_H
#define APPSTATE_H

#include <Arduino.h>

// Enumeration of operational modes in MATA
enum AppState {
  STATUS_SCREEN,
  PACKET_SNIFF,
  DEAUTH_ATTACK,
  JAM_MODE,
  REPLAY_MODE,
  DIAGNOSTICS,
  PLUGIN_PANEL
};

extern AppState currentAppState;  // Global current mode

void setAppState(AppState state);  // Sets mode with optional feedback
AppState getAppState();            // Returns current mode
void renderCurrentState();         // Loads screen for current mode

#endif
