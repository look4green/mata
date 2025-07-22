#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <Arduino.h>

void initBluetooth();                 // Start serial-over-Bluetooth
void updateBluetooth();              // Check for incoming commands
void sendBluetoothMessage(const String& msg);  // Echo to terminal

#endif
