#include <Wire.h>
#include <Servo.h>
#include <MPU6050.h>

MPU6050 mpu;

Servo esc1, esc2, esc3, esc4;

const int ch1 = 2;  // Roll
const int ch2 = 4;  // Pitch
const int ch3 = 7;  // Throttle
const int ch4 = 8;  // Yaw

int throttle, pitch, roll, yaw;
int16_t ax, ay, az, gx, gy, gz;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();

  pinMode(ch1, INPUT);
  pinMode(ch2, INPUT);
  pinMode(ch3, INPUT);
  pinMode(ch4, INPUT);

  esc1.attach(3);  // Avant gauche
  esc2.attach(5);  // Avant droit
  esc3.attach(6);  // Arrière gauche
  esc4.attach(9);  // Arrière droit

  // Armer les moteurs
  esc1.writeMicroseconds(1000);
  esc2.writeMicroseconds(1000);
  esc3.writeMicroseconds(1000);
  esc4.writeMicroseconds(1000);
  delay(3000);
}

void loop() {
  // Lecture des canaux RC
  roll     = pulseIn(ch1, HIGH, 25000);
  pitch    = pulseIn(ch2, HIGH, 25000);
  throttle = pulseIn(ch3, HIGH, 25000);
  yaw      = pulseIn(ch4, HIGH, 25000);

  // Lecture des données MPU6050
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Appliquer des corrections simplifiées avec gyroscope
  int correction_pitch = gy / 100;
  int correction_roll  = gx / 100;

  // Calcul des vitesses par moteur
  int m1 = throttle - correction_pitch + correction_roll;
  int m2 = throttle - correction_pitch - correction_roll;
  int m3 = throttle + correction_pitch + correction_roll;
  int m4 = throttle + correction_pitch - correction_roll;

  // Envoi aux ESC
  esc1.writeMicroseconds(constrain(m1, 1000, 2000));
  esc2.writeMicroseconds(constrain(m2, 1000, 2000));
  esc3.writeMicroseconds(constrain(m3, 1000, 2000));
  esc4.writeMicroseconds(constrain(m4, 1000, 2000));

  delay(20);
}
