//Pins required for photosensors
int sensor_l = A0;
int sensor_c = A1;
int sensor_r = A2;

int sensorvalue_l = 0;
int sensorvalue_c = 0;
int sensorvalue_r = 0;

void line_follow(void) {

/*if(lineSensor_Calibration == 0){

  int initial_l = analogRead(sensor_l);
  int initial_c = analogRead(sensor_c);
  int initial_r = analogRead(sensor_r);

  int threshold_lh = initial_l+100;
  int threshold_ll = initial_l+50;
  int threshold_ch = initial_c+100;
  int threshold_cl = initial_c+50;
  int threshold_rh = initial_r+100;
  int threshold_rl = initial_r+50;
  
    
}
lineSensor_Calibration = true;*/

motor_l->setSpeed(150);
motor_r->setSpeed(150);

sensorvalue_l = analogRead(sensor_l);
sensorvalue_c = analogRead(sensor_c);
sensorvalue_r = analogRead(sensor_r);

/*Serial.print("left sensor ");
Serial.print(sensorvalue_l);

Serial.print("centre sensor ");
Serial.print(sensorvalue_c);

Serial.print("right sensor ");
Serial.print(sensorvalue_r);

Serial.println();*/

if (sensorvalue_l >= 900 && sensorvalue_c <= 800 && sensorvalue_r >= 900) {

  
motor_l->setSpeed(150);
motor_r->setSpeed(150);

  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);

  Serial.println("010 Straight");
}

else if (sensorvalue_l >= 900 && sensorvalue_c <= 800 && sensorvalue_r <= 800) {


motor_l->setSpeed(200);
motor_r->setSpeed(200);
  motor_l->run(BACKWARD);
  motor_r->run(FORWARD);

  Serial.println("011 Turn right");
  }

else if (sensorvalue_l >= 900 && sensorvalue_c >= 900 && sensorvalue_r <= 800) {

  
motor_l->setSpeed(200);
motor_r->setSpeed(200);
  motor_l->run(BACKWARD);
  motor_r->run(FORWARD);

  Serial.println("001 Turn right");
}

else if (sensorvalue_l <= 800 && sensorvalue_c <= 800 && sensorvalue_r >= 900) {


motor_l->setSpeed(200);
motor_r->setSpeed(200);
  motor_l->run(FORWARD);
  motor_r->run(BACKWARD);

  Serial.println("110 Turn left");
}

else if (sensorvalue_l <= 800 && sensorvalue_c >= 900 && sensorvalue_r >= 900) {


motor_l->setSpeed(200);
motor_r->setSpeed(200);
  motor_l->run(FORWARD);
  motor_r->run(BACKWARD);

  Serial.println("100 Turn left");
}

else if (sensorvalue_l <= 800 && sensorvalue_c <= 900 && sensorvalue_r <= 900) {

motor_l->setSpeed(200);
motor_r->setSpeed(200);
  motor_l->run(BACKWARD);
  motor_r->run(FORWARD);

  Serial.println("111 Turn right");
}

else if(sensorvalue_l <=800 && sensorvalue_c >=900 && sensorvalue_r <=800) {

   motor_l->setSpeed(200);
  motor_r->setSpeed(200);
  motor_l->run(BACKWARD);
  motor_r->run(FORWARD);  
}
else {

motor_l->setSpeed(150);
motor_r->setSpeed(150);
  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);

  Serial.println("nada");
}
return;
   }
