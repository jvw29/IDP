#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Wire.h>
/*#define echopin A4 // echo pin
#define trigpin A5 // Trigger pin*/

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *motor_l = AFMS.getMotor(2);
Adafruit_DCMotor *motor_r = AFMS.getMotor(1);

void setup() {
  // put your setup code here, to run once:
 AFMS.begin();

}

void loop() {

  motor_l->setSpeed(150);
  motor_r->setSpeed(150);
  // put your main code here, to run repeatedly:

  motor_l->run(FORWARD);
  motor_r->run(FORWARD);
}
