#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

//Setup motors
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);
Adafruit_DCMotor *motor3 = AFMS.getMotor(3);
Adafruit_DCMotor *motor4 = AFMS.getMotor(4);

//Assign values to pins
const int trigPin1 = 8;
const int echoPin1 = 9;

const int trigPin2 = 10;
const int echoPin2 = 11;

const int trigPin3 = 12;
const int echoPin3 = 13;

void setup() {
  // put your setup code here, to run once:
AFMS.begin();

pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input

pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);

pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int distance_ahead;
long duration_ahead;

int distance_left, distance_right;

long duration_left, duration_right;

digitalWrite(trigPin1,LOW);
delayMicroseconds(2);

digitalWrite(trigPin1,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1,LOW);

//Calculates distance from nearest object ahead of robot
duration_ahead = pulseIn(echoPin1,HIGH);

distance_ahead = duration_ahead*0.034/2;

if (distance_ahead <= 50) {

  digitalWrite(trigPin2,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);

  duration_left = pulseIn(echoPin2,HIGH);

  digitalWrite(trigPin3,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin3,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3,LOW);
  
  duration_right = pulseIn(echoPin3,HIGH);

  //Calculate distance nearest object is from left and right of robot
  distance_left = duration_left*0.034/2;
  distance_right = duration_right*0.034/2;

  /*Serial.print("Distance left:");
  Serial.println(distance_left);

  Serial.print("Distance right:");
  Serial.println(distance_right);*/


  //Whichever distance is lowest, robot turns in direction away from
  if (distance_right < distance_left) {

    motor1->setSpeed(150);
    motor2->setSpeed(150);
    motor3->setSpeed(150);
    motor4->setSpeed(150);

    motor1->run(BACKWARD);
    motor2->run(FORWARD);
    motor3->run(FORWARD);
    motor4->run(BACKWARD);
  }

  else {

    motor1->setSpeed(150);
    motor2->setSpeed(150);
    motor3->setSpeed(150);
    motor4->setSpeed(150);

    motor1->run(FORWARD);
    motor2->run(BACKWARD);
    motor3->run(BACKWARD);
    motor4->run(FORWARD);
  }
}

else {

  //Robot moves straight ahead
  motor1->setSpeed(100);
  motor2->setSpeed(100);
  motor3->setSpeed(100);
  motor4->setSpeed(100);

  motor1->run(FORWARD);
  motor2->run(FORWARD);
  motor3->run(FORWARD);
  motor4->run(FORWARD);
}

}
