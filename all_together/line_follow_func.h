//Pins required for photosensors
int sensor_l = A0;
int sensor_c = A1;
int sensor_r = A2;

int sensorvalue_l = 0;
int sensorvalue_c = 0;
int sensorvalue_r = 0;

void line_follow(void) {

if(lineSensor_Calibration == 0){

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
lineSensor_Calibration = true;

motor_l->setSpeed(150);
motor_r->setSpeed(150);

sensorvalue_l = analogRead(sensor_l);
sensorvalue_c = analogRead(sensor_c);
sensorvalue_r = analogRead(sensor_r);
  
if (sensorvalue_l >= threshold_lh && sensorvalue_c <= threshold_cl && sensorvalue_r >= threshold_rh) {

  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);

//  Serial.println("010 Straight");
}

else if (sensorvalue_l >= threshold_lh && sensorvalue_c <= threshold_cl && sensorvalue_r <= threshold_rl) {

  motor_l->run(BACKWARD);
  motor_r->run(FORWARD);

//  Serial.println("011 Turn right");
  }

else if (sensorvalue_l >= threshold_lh && sensorvalue_c >= threshold_ch && sensorvalue_r <= threshold_rl) {
  
  motor_l->run(BACKWARD);
  motor_r->run(FORWARD);

//  Serial.println("001 Turn right");
}

else if (sensorvalue_l <= threshold_ll && sensorvalue_c <= threshold_cl && sensorvalue_r >= threshold_rh) {

  motor_l->run(FORWARD);
  motor_r->run(BACKWARD);

//  Serial.println("110 Turn left");
}

else if (sensorvalue_l <= threshold_ll && sensorvalue_c >= threshold_ch && sensorvalue_r >= threshold_rh) {

  motor_l->run(FORWARD);
  motor_r->run(BACKWARD);

//  Serial.println("100 Turn left");
}

else if (sensorvalue_l <= threshold_ll && sensorvalue_c <= threshold_cl && sensorvalue_r <= threshold_rl) {

  motor_l->run(BACKWARD);
  motor_r->run(FORWARD);

//  Serial.println("111 Turn right");
}
else {

  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);
}

return;
}
