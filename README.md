# Smart-Soil-Irrigation-System-using-Arduino-Uno


An automated irrigation system built using **Arduino Uno** that continuously monitors soil moisture and automatically controls a water pump to maintain healthy soil conditions. The system provides real-time information on an OLED display, visual LED indicators, and an audible alert whenever irrigation is required.

---

# 📖 Objective

The objective of this project is to develop a **Smart Soil Irrigation System** that can automatically detect dry soil conditions and irrigate plants without manual intervention.

The system continuously measures soil moisture, displays the moisture percentage on an OLED screen, and automatically switches the water pump ON or OFF depending on the moisture level.

---

# ✨ Features

* 🌱 Real-time soil moisture monitoring.
* 💧 Displays soil moisture percentage (0–100%).
* 🚰 Automatically turns the water pump ON when soil is dry.
* ⛔ Automatically turns the pump OFF when sufficient moisture is reached.
* 🟢 Green LED indicates healthy soil conditions.
* 🔴 Red LED indicates dry soil and pump operation.
* 🔔 Active buzzer alerts while irrigation is active.
* 📟 OLED displays moisture level, soil status, and pump status.
* 📊 Horizontal progress bar showing moisture level.
* 💻 Serial Monitor output for debugging.

---

# 🛠 Components Required

* Arduino Uno
* Soil Moisture Sensor
* SSD1306 I2C OLED Display (128×64)
* 1-Channel Relay Module
* Mini DC Water Pump
* External Power Supply (5V–12V)
* Active Buzzer
* Green LED
* Red LED
* 220Ω Resistors
* Breadboard
* Jumper Wires

---

# 🔌 Circuit Connections

## Soil Moisture Sensor

| Sensor Pin | Arduino Uno |
| ---------- | ----------- |
| VCC        | 5V          |
| GND        | GND         |
| AO         | A0          |

---

## OLED Display

| OLED Pin | Arduino Uno |
| -------- | ----------- |
| VCC      | 5V          |
| GND      | GND         |
| SDA      | A4          |
| SCL      | A5          |

---

## Relay Module

| Relay Pin | Arduino Uno |
| --------- | ----------- |
| IN        | D7          |
| VCC       | 5V          |
| GND       | GND         |

---

## LEDs

### Green LED

| LED Pin     | Arduino Uno                |
| ----------- | -------------------------- |
| Anode (+)   | D5 (through 220Ω resistor) |
| Cathode (-) | GND                        |

### Red LED

| LED Pin     | Arduino Uno                |
| ----------- | -------------------------- |
| Anode (+)   | D6 (through 220Ω resistor) |
| Cathode (-) | GND                        |

---

## Active Buzzer

| Buzzer Pin   | Arduino Uno |
| ------------ | ----------- |
| Positive (+) | D8          |
| Negative (-) | GND         |

---

## Water Pump Connection

```
External Power (+)
        │
       COM
        │
     Relay Module
        │
       NO
        │
     Pump (+)

Pump (-)
        │
External Power (-)
```

> **Important:** Do **not** power the water pump directly from the Arduino. Always use an external power supply through the relay module.

---

# ⚙️ Working Principle

1. The soil moisture sensor continuously measures the moisture level.
2. The Arduino converts the analog sensor value into a moisture percentage.
3. If the moisture level falls below the predefined threshold:

   * The relay activates the water pump.
   * The red LED turns ON.
   * The buzzer sounds.
   * The OLED displays **Pump: ON**.
4. When the soil moisture reaches the desired level:

   * The relay switches OFF the pump.
   * The green LED turns ON.
   * The buzzer stops.
   * The OLED displays **Pump: OFF**.

---

# 🖥 OLED Display

### Normal Condition

```
SMART IRRIGATION
-----------------------

Moisture : 72%

Status : GOOD

Pump : OFF

██████████████████
```

---

### Dry Soil

```
SMART IRRIGATION
-----------------------

Moisture : 18%

Status : DRY

Pump : ON

████
```



# 📸 Output Images
IMAGE 1:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/48275024-4073-46dc-9d43-f4fc9a07b2d8" />
IMAGE 2:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/e2168b2d-c357-41e2-9cca-e9730a268b7a" />

# 💻 Software Used

* Arduino IDE
* Embedded C / Arduino Programming Language

---

# 📚 Libraries Required

Install the following libraries using the Arduino IDE Library Manager:

* Adafruit GFX Library
* Adafruit SSD1306 Library
* Wire Library (built into Arduino IDE)

---

# 🎯 Learning Outcomes

Through this project, you will learn:

* Soil moisture sensing techniques.
* Analog sensor interfacing with Arduino.
* Relay module interfacing.
* Water pump control.
* OLED display programming.
* LED and buzzer interfacing.
* Sensor calibration.
* Embedded automation systems.
* Smart agriculture concepts.
* Real-time monitoring using Arduino.

---

# 🚀 Future Enhancements

* Automatic water level monitoring.
* Mobile app control using Bluetooth.
* Wi-Fi monitoring using ESP8266/ESP32.
* IoT dashboard using cloud services.
* Solar-powered irrigation system.
* Weather forecast integration.
* Scheduled irrigation.
* Data logging to SD card.

---

# 🛠 Technologies Used

* Arduino Uno
* Embedded C
* Soil Moisture Sensor
* SSD1306 OLED Display
* Relay Module
* DC Water Pump
* Arduino IDE

---

# ⭐ Support

If you found this project useful, consider giving this repository a **⭐ Star** and feel free to **Fork** it to build your own smart irrigation system.

Happy Coding! 🌱💧

