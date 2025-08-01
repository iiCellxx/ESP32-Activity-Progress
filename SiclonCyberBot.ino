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