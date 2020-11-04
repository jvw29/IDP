#include <Servo.h> 

Servo servo;

void door_open(void) {

  for (int pos = 120; pos >= 0; pos--) {

      servo.write(pos);
      delay(15); 
  }


  return;
}

void door_close(void) {

  
  for (int pos = 0; pos <= 120; pos++) {

      servo.write(pos);
      delay(15); 
  }

  return;
}

void pickup(void) {

  motor_r->setSpeed(150);
  motor_l->setSpeed(150);

  motor_r->run(FORWARD);
  motor_l->run(FORWARD);
    
  delay(1000);

  motor_r->setSpeed(0);
  motor_l->setSpeed(0);
    
  door_open();

  motor_r->setSpeed(150);
  motor_l->setSpeed(150);

  motor_r->run(BACKWARD);
  motor_l->run(BACKWARD);

  delay(3000);

  motor_r->setSpeed(0);
  motor_l->setSpeed(0);

  motor_r->run(BACKWARD);
  motor_l->run(BACKWARD);
  
  door_close();

  
  motor_r->setSpeed(150);
  motor_l->setSpeed(150);
  
  motor_r->run(FORWARD);
  motor_l->run(FORWARD);

  delay(2000);

  return;
}

void dropoff(void) {

  motor_r->setSpeed(0);
  motor_l->setSpeed(0);
    
  door_open();

  motor_r->setSpeed(150);
  motor_l->setSpeed(150);

  motor_r->run(BACKWARD);
  motor_l->run(BACKWARD);

  delay(750);

  door_close();

  return;
}
