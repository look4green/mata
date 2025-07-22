#include "RF.h"
#include "Display.h"
#include <SPI.h>
#include <RF24.h>  // Ensure NRF24L01 support
#include <ELECHOUSE_CC1101_SRC_DRV.h>  // For CC1101 ops

// NRF instance — adjust pins if needed
RF24 nrf(17, 5);  // CE, CSN

void setNRFFrequency(int channel) {
  nrf.setChannel(channel);
  drawStatus("NRF channel set: " + String(channel));
}

void launchDeauth() {
  nrf.begin();
  nrf.setPALevel(RF24_PA_HIGH);
  nrf.setChannel(6);  // Example channel
  nrf.setDataRate(RF24_2MBPS);

  byte payload[] = {0xDE, 0xAD, 0xBE, 0xEF};  // Example deauth frame

  for (int i = 0; i < 100; i++) {
    nrf.write(payload, sizeof(payload));
    delay(10);  // Packet spacing
  }

  drawStatus("Deauth sent");
}

void startJammer() {
  ELECHOUSE_cc1101.Init();
  ELECHOUSE_cc1101.setMHZ(433.0);  // Set frequency
  ELECHOUSE_cc1101.SetTx();        // Switch to transmit mode

  byte jamData[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

  for (int i = 0; i < 300; i++) {
    ELECHOUSE_cc1101.SendData(jamData, 6);
    delay(5);
  }

  drawStatus("Jamming burst complete");
}

void replaySignal() {
  File replay = SD.open("/replay/data.bin");
  if (!replay) {
    drawStatus("Replay file missing");
    return;
  }

  byte buffer[32];
  while (replay.available()) {
    int len = replay.readBytes(buffer, 32);
    nrf.write(buffer, len);
    delay(15);
  }

  replay.close();
  drawStatus("Replay finished");
}
