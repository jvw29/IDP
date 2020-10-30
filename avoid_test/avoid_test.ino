#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Wire.h>
#include <Arduino_LSM6DS3.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *motor_l = AFMS.getMotor(2);
Adafruit_DCMotor *motor_r = AFMS.getMotor(1);

int sensor_l =A0;
int sensor_c = A1;
int sensor_r = A2;
int sensorvalue_l = 0;
int sensorvalue_c = 0;
int sensorvalue_r = 0;

void setup() {
  // put your setup code here, to run once:
AFMS.begin();

Serial.begin(9600);

  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

motor_r->run(FORWARD);
motor_l->run(FORWARD);

motor_r->setSpeed(150);
motor_l->setSpeed(150);

delay(1000);

float x, y, z, yaw, dt;

yaw = 0;
dt = 104.445;

motor_r->setSpeed(0);
motor_l->setSpeed(0);

motor_r->run(FORWARD);
motor_l->run(FORWARD);


//Left turn
while (yaw <= 70) {
  //Serial.println(yaw);
  if (IMU.gyroscopeAvailable()) {
      IMU.readGyroscope(x, y, z);

  //Serial.println("turn left");
  //Serial.println(z);
  z += 3.7;
  
  motor_r->setSpeed(150);
  motor_l->setSpeed(150);
  motor_r->run(BACKWARD);
  motor_l->run(FORWARD);

  yaw += z/dt;

  //Serial.println(yaw);
  
  }
}

motor_r->run(BACKWARD);
motor_l->run(BACKWARD);

delay(2000);

motor_r->setSpeed(0);
motor_l->setSpeed(0);

motor_r->run(BACKWARD);
motor_l->run(BACKWARD);

//Right turn 1
while (yaw > 10) {

  //Serial.println("right1");
  if (IMU.gyroscopeAvailable()) {
      IMU.readGyroscope(x, y, z);
  
  z += 3.7;
  
  /*Serial.print(x);
  Serial.print(y);
  Serial.print(z);
  Serial.println();*/

  motor_r->setSpeed(150);
  motor_l->setSpeed(150);
  motor_r->run(FORWARD);
  motor_l->run(BACKWARD);

  yaw += z/dt;

  //Serial.println(yaw);
  }
}

motor_r->run(BACKWARD);
motor_l->run(BACKWARD);

delay(3500);

motor_r->setSpeed(0);
motor_l->setSpeed(0);

motor_r->run(BACKWARD);
motor_l->run(BACKWARD);

//Right turn 2
while (yaw > -70) {

  //Serial.println("right2");
  if (IMU.gyroscopeAvailable()) {
      IMU.readGyroscope(x, y, z);
  
  z += 3.7;
  
  motor_r->setSpeed(150);
  motor_l->setSpeed(150);
  
  motor_r->run(FORWARD);
  motor_l->run(BACKWARD);

  yaw += z/dt;

  //Serial.println(yaw);
  }
}

motor_r->run(BACKWARD);
motor_l->run(BACKWARD);

for (int i=0; i < 100000000; i++) {

  sensorvalue_l = analogRead(sensor_l);
  sensorvalue_c = analogRead(sensor_c);
  sensorvalue_r = analogRead(sensor_r);

  if (sensorvalue_l <= 400 && sensorvalue_c <= 400 /*|| sensorvalue_r <= 400*/) {

  motor_r->setSpeed(150);
  motor_l->setSpeed(150);

  motor_r->run(BACKWARD);
  motor_l->run(FORWARD);

  
  delay(500);
}
}
}
