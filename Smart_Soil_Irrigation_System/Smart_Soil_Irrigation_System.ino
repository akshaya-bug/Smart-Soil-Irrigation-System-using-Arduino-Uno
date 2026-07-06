#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pins
#define SOIL_PIN A0
#define RELAY_PIN 7
#define RED_LED 4
#define YELLOW_LED 5
#define GREEN_LED 6
#define BUZZER 8

// Calibration Values
#define DRY_VALUE 1023
#define WET_VALUE 300

bool pumpState = false;

void setup() {

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH); // Relay OFF

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();

  // Splash Screen
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(5, 20);
  display.println("SMART");
  display.println("IRRIGATION");
  display.display();

  delay(2000);
}

void loop() {

  int soilRaw = analogRead(SOIL_PIN);

  int moisture =
      map(soilRaw, DRY_VALUE, WET_VALUE, 0, 100);

  moisture = constrain(moisture, 0, 100);

  bool newPumpState = false;

  // Soil Dry
  if (moisture < 40) {

    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);

    digitalWrite(RELAY_PIN, LOW); // Pump ON
    newPumpState = true;
  }

  // Medium
  else if (moisture < 70) {

    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);

    digitalWrite(RELAY_PIN, HIGH);
  }

  // Wet
  else {

    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

    digitalWrite(RELAY_PIN, HIGH);
  }

  // Buzzer on state change
  if (newPumpState != pumpState) {

    tone(BUZZER, 1000, 300);
    pumpState = newPumpState;
  }

  // OLED Display
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Soil Moisture");

  display.setTextSize(2);
  display.setCursor(15, 15);
  display.print(moisture);
  display.print("%");

  // Progress Bar
  display.drawRect(10, 45, 108, 10, WHITE);
  display.fillRect(12, 47,
                   map(moisture, 0, 100, 0, 104),
                   6, WHITE);

  display.setTextSize(1);
  display.setCursor(0, 58);

  if (pumpState)
    display.print("Pump: ON");
  else
    display.print("Pump: OFF");

  display.display();

  delay(1000);
}