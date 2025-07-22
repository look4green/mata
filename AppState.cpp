#include "AppState.h"
#include "Display.h"
#include "RF.h"
#include "Diagnostics.h"
#include "PluginManager.h"

AppState currentAppState = STATUS_SCREEN;

void setAppState(AppState state) {
  currentAppState = state;
  renderCurrentState();
}

AppState getAppState() {
  return currentAppState;
}

void renderCurrentState() {
  clearScreen();

  switch (currentAppState) {
    case STATUS_SCREEN:
      drawTitleBar("Status");
      drawStatus("MATA Ready");
      break;

    case PACKET_SNIFF:
      drawTitleBar("Sniff");
      drawStatus("Listening...");
      // Future: startSniffer()
      break;

    case DEAUTH_ATTACK:
      drawTitleBar("Deauth");
      drawStatus("Launching attack");
      launchDeauth();  // from RF.cpp
      break;

    case JAM_MODE:
      drawTitleBar("Jam");
      drawStatus("Jamming signal");
      startJammer();  // from RF.cpp
      break;

    case REPLAY_MODE:
      drawTitleBar("Replay");
      drawStatus("Replaying traffic");
      replaySignal();  // from RF.cpp
      break;

    case DIAGNOSTICS:
      drawTitleBar("Diagnostics");
      showSignalStrength();  // from Diagnostics.cpp
      break;

    case PLUGIN_PANEL:
      drawTitleBar("Plugins");
      listPlugins();  // from PluginManager.cpp
      break;

    default:
      drawStatus("Unknown mode");
      break;
  }
}
