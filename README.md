# MATA

⚡ **Modular Adaptive Tactical Array**  
A customizable ESP32-based wireless toolkit for signal explorers, security researchers, and tactical interface designers.

---

## 🧩 Features

- 📲 Touchscreen + rotary encoder UI
- 📡 Wi-Fi scan, deauth, packet sniffing
- 📻 Sub-GHz replay, jamming, NRF + CC1101 control
- 💾 SD-backed mode profiles + logging
- 🧪 Diagnostics with RSSI graph and module check
- 🔋 Auto-dimming + power management
- 🎨 Touch ripple animation + theme support
- 🔌 Plugin system (LoRa, GPS, IR-ready)

---

## 🛠 Hardware Requirements

| Module        | Purpose                    |
|---------------|----------------------------|
| ESP32-WROOM   | Core MCU                   |
| ILI9341 TFT   | Display output             |
| XPT2046       | Touch input                |
| Rotary Encoder| Menu navigation            |
| SD Module     | Profiles + logging         |
| NRF24L01      | Deauth + replay            |
| CC1101        | Sub-GHz capture/jam        |

Optional:
- LoRa, GPS, IR modules via plugins

---

## 🚀 Getting Started

1. Wire up hardware (see `/docs/wiring.pdf`)
2. Flash firmware via PlatformIO or Arduino IDE
3. Insert SD card with `/profiles/` and `/themes/`
4. Power up and witness the **MATA** splash
5. Navigate, load profiles, and deploy wirelessly

---

## 🧬 Project Identity

> _Built for users who demand more than scripts._  
> _MATA is adaptive. Modular. Tactical._  
> _A toolkit with style, precision, and purpose._

---

## 📂 Repo Structure
                                  MATA/ │ 
                                        ├── src/             
              ← Firmware modules        ├── assets/          
              ← Splash, icons           ├── data/            
              ← SD signal logs, config  ├── docs/            
              ← Wiring guide, diagrams  ├── themes/         
              ← JSON UI themes          ├── profiles/        
              ← Prebuilt attack configs ├── platformio.ini   
              ← Build config            ├── LICENSE          
              ← MIT                     └── README.md        
              ← You're reading it

---

## 📜 License

MIT — use freely, attribute wisely.

---

## 🧠 Credits

Built by [21Keju], refined with Copilot.  
Signal artistry meets firmware engineering.

---
