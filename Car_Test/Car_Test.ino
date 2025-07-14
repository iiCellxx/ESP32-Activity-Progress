#define REMOTEXY_MODE__WIFI_POINT
#include <WiFi.h>
#define REMOTEXY_WIFI_SSID "SieraSiclonAlmario2"
#define REMOTEXY_WIFI_PASSWORD "123456789"
#define REMOTEXY_SERVER_PORT 6377
#include <RemoteXY.h>
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = { 255,4,0,0,0,61,0,19,0,0,0,0,7,2,106,200,200,84,1,1,
  3,0,5,216,29,143,143,10,14,60,60,0,23,26,31,2,56,34,23,52,
  142,5,44,22,0,2,26,31,31,79,78,0,79,70,70,0,4,54,64,7,
  86,83,56,112,13,128,2,26 };
struct {
  int8_t joystick_01_x;
  int8_t joystick_01_y;
  uint8_t switch_01;
  int8_t slider_01;
  uint8_t connect_flag;
} RemoteXY;
#pragma pack(pop)
const int IN1 = 16;
const int IN2 = 17;
const int IN3 = 18;
const int IN4 = 19;
const int ENA = 22;
const int ENB = 23;
void setup() {
  RemoteXY_Init();
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}
void loop() {
  RemoteXY_Handler();
  if (RemoteXY.switch_01 == 1) {
    int speed = RemoteXY.slider_01 * 2.55;
    int speedLeft = speed;
    int speedRight = speed;
    if (abs(RemoteXY.joystick_01_y) >= 100) {
      if (RemoteXY.joystick_01_y > 0) {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
      } else {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
      }
      if (RemoteXY.joystick_01_x >= 90) {
        speedLeft = speed / 2;
      } else if (RemoteXY.joystick_01_x <= -90) {
        speedRight = speed / 2;
      }
      analogWrite(ENA, speedLeft);
      analogWrite(ENB, speedRight);
    } else if (abs(RemoteXY.joystick_01_x) >= 100) {
      if (RemoteXY.joystick_01_x > 0) {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
      } else {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
      }
      analogWrite(ENA, speed);
      analogWrite(ENB, speed);
    } else {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
    }
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
  }
}