#include "Display.h"
#include "Splash.h"
#include "Touchscreen.h"
#include "PowerManager.h"
#include "ThemeManager.h"
#include "PluginManager.h"
#include "Plugin.h"
#include "Storage.h"
#include "Calibration.h"
#include "AppState.h"
#include "RF.h"
#include "Menu.h"
#include "Diagnostics.h"
#include "Bluetooth.h"
#include "Settings.h"
#include "SettingsUI.h"
#include "ProfileSelector.h"
#include "Icon.h"

void setup() {
  Serial.begin(115200);

  initDisplay();
  initTouchscreen();
  initPowerManager();
  initBluetooth();
  loadSettings();                           // 🧠 Load saved preferences
  loadTheme(getThemeName());                // 🎨 Apply preferred theme
  initStorage();
  showSplash();                              // 🧬 Branded boot screen

  initMenu();
  initPlugins();
  initProfileSelector();
  initSettingsPanel();

  setAppState(STATUS_SCREEN);               // 📺 Default startup mode
}

void loop() {
  updatePowerManager();
  updateTouch();
  updateBluetooth();

  switch (getAppState()) {
    case STATUS_SCREEN: /* optional status loop */ break;
    case PACKET_SNIFF: /* packet sniffing logic */ break;
    case DEAUTH_ATTACK: /* deauth logic */ break;
    case JAM_MODE: /* jam logic */ break;
    case REPLAY_MODE: /* replay logic */ break;
    case DIAGNOSTICS: updateDiagnostics(); break;
    case PLUGIN_PANEL: updatePlugins(); break;
    case SETTINGS_PANEL: updateSettingsPanel(); break;
    case PROFILE_PANEL: updateProfileSelector(); break;
    default: updateMenu(); break;
  }

  updateMenu();               // 🧭 UI stays responsive
}
