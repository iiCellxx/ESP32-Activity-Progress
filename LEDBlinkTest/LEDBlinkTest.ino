/*
  LED Blink Test
  ✅ Onboard LED (GPIO 2)
  ✅ External LED on GPIO 15 with 220Ω resistor
*/

#define ONBOARD_LED 2
#define EXTERNAL_LED 15

void setup() {
  pinMode(ONBOARD_LED, OUTPUT);
  pinMode(EXTERNAL_LED, OUTPUT);
}

void loop() {
  digitalWrite(ONBOARD_LED, HIGH);
  digitalWrite(EXTERNAL_LED, HIGH);
  delay(500);

  digitalWrite(ONBOARD_LED, LOW);
  digitalWrite(EXTERNAL_LED, LOW);
  delay(500);
}
