int trigPin = 10;
int echoPin = 11;

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
#include "avoid_func_test.h"

bool started = false;
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
if (started == 0) {

  motor_l->setSpeed(150);
  motor_r->setSpeed(150);

  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);

  delay(1000);

  started = true;
}

int duration;
  int distance;
  
  digitalWrite(trigPin, LOW);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.034/2;

  sensorvalue_l = analogRead(sensor_l);
sensorvalue_c = analogRead(sensor_c);
sensorvalue_r = analogRead(sensor_r);

  if (distance > 30 || distance <= 15) {

    avoid();    
  }

  else {




/*Serial.print("left sensor ");
Serial.print(sensorvalue_l);

Serial.print("centre sensor ");
Serial.print(sensorvalue_c);

Serial.print("right sensor ");
Serial.print(sensorvalue_r);

Serial.println();*/
  
if (sensorvalue_l >= 500 && sensorvalue_c <= 400 && sensorvalue_r >= 500) {

  
motor_l->setSpeed(150);
motor_r->setSpeed(150);

  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);

//  Serial.println("010 Straight");
}

else if (sensorvalue_l >= 500 && sensorvalue_c <= 400 && sensorvalue_r <= 400) {


motor_l->setSpeed(150);
motor_r->setSpeed(150);
  motor_l->run(BACKWARD);
  motor_r->run(FORWARD);

//  Serial.println("011 Turn right");
  }

else if (sensorvalue_l >= 500 && sensorvalue_c >= 500 && sensorvalue_r <= 400) {

  
motor_l->setSpeed(150);
motor_r->setSpeed(150);
  motor_l->run(BACKWARD);
  motor_r->run(FORWARD);

//  Serial.println("001 Turn right");
}

else if (sensorvalue_l <= 400 && sensorvalue_c <= 400 && sensorvalue_r >= 500) {


motor_l->setSpeed(150);
motor_r->setSpeed(150);
  motor_l->run(FORWARD);
  motor_r->run(BACKWARD);

//  Serial.println("110 Turn left");
}

else if (sensorvalue_l <= 400 && sensorvalue_c >= 500 && sensorvalue_r >= 500) {


motor_l->setSpeed(150);
motor_r->setSpeed(150);
  motor_l->run(FORWARD);
  motor_r->run(BACKWARD);

//  Serial.println("100 Turn left");
}

else if (sensorvalue_l <= 400 && sensorvalue_c <= 400 && sensorvalue_r <= 400) {

motor_l->setSpeed(150);
motor_r->setSpeed(150);
  motor_l->run(BACKWARD);
  motor_r->run(FORWARD);

//  Serial.println("111 Turn right");
}
else {

motor_l->setSpeed(150);
motor_r->setSpeed(150);
  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);

//  Serial.println("nada");
}
   }
}
