#include "Bluetooth.h"
#include "AppState.h"
#include "Display.h"
#include <BluetoothSerial.h>

BluetoothSerial btSerial;

void initBluetooth() {
  if (!btSerial.begin("MATA-Toolkit")) {
    drawStatus("Bluetooth failed");
    return;
  }
  drawStatus("Bluetooth ready");
}

void updateBluetooth() {
  if (btSerial.available()) {
    String command = btSerial.readStringUntil('\n');
    command.trim();
    drawStatus("BT CMD: " + command);

    // 🧠 Example commands:
    if (command == "deauth") setAppState(DEAUTH_ATTACK);
    else if (command == "jam") setAppState(JAM_MODE);
    else if (command == "sniff") setAppState(PACKET_SNIFF);
    else if (command == "replay") setAppState(REPLAY_MODE);
    else sendBluetoothMessage("Unknown command");
  }
}

void sendBluetoothMessage(const String& msg) {
  btSerial.println("[MATA] " + msg);
}
