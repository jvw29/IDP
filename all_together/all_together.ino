#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Wire.h>
#include <Arduino_LSM6DS3.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *motor_l = AFMS.getMotor(2);
Adafruit_DCMotor *motor_r = AFMS.getMotor(1);

#include "LDR.h"
#include "line_follow_func.h"
#include "ultrasonic.h"
#include "avoid_movement_func.h"
#include "door_mechs.h"
#include "move_to_container.h"

int greenled_pin = 3;
int redled_pin = 4;

float distance_travelled = 0;

void setup() {
  // put your setup code here, to run once:
  AFMS.begin();

  servo.attach(10);

  Serial.begin(9600);

  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenled_pin, OUTPUT);
  pinMode(redled_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(greenled_pin, LOW);
digitalWrite(redled_pin, LOW);
if (distance_travelled  < 10){
  
}

else if (10 <= distance_travelled <= 5000) {

//Check if there is fruit within range
bool obstacle = ultrasonic();

//If no obstacle is detected, follow the line
if (obstacle == 0) {

  line_follow();
}

if (obstacle == 1) {
  
  //Detect colour
  bool ripe = LDR();
  
  //If red, pick up
  if (ripe == 1) {

    motor_r->setSpeed(0);
    motor_l->setSpeed(0);

    digitalWrite(greenled_pin, HIGH);

    delay(5000);

    digitalWrite(greenled_pin, LOW);

    pickup();
    
  }
  
  //If blue, move to avoid
  if (ripe == 0) {

    motor_r->setSpeed(0);
    motor_l->setSpeed(0);

    digitalWrite(redled_pin, HIGH);

    delay(5000);

    digitalWrite(redled_pin, LOW);
    
    motor_r->setSpeed(150);
    motor_l->setSpeed(150);

    motor_r->run(FORWARD);
    motor_l->run(FORWARD);

    delay(1000);

    avoid();
  }
}
}

else if (distance_travelled > 5000) {

  bool container_reached = move_to_container();

  if (container_reached == 1) {

    delay(1000);

    dropoff();

    
  }
}
}
