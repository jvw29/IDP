void avoid(void) {

  float x, y, z, yaw, dt;

yaw = 0;
dt = 104.445;

motor_r->setSpeed(0);
motor_l->setSpeed(0);

motor_r->run(FORWARD);
motor_l->run(FORWARD);


//Left turn
while (yaw <= 90) {
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

delay(500);

motor_r->setSpeed(0);
motor_l->setSpeed(0);

motor_r->run(BACKWARD);
motor_l->run(BACKWARD);

//Right turn 1
while (yaw > 0) {

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

delay(1000);

motor_r->setSpeed(0);
motor_l->setSpeed(0);

motor_r->run(BACKWARD);
motor_l->run(BACKWARD);

//Right turn 2
while (yaw > -90) {

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

  if (sensorvalue_l <= 900 || sensorvalue_c <= 900 || sensorvalue_r <= 900) {

  motor_r->setSpeed(150);
  motor_l->setSpeed(150);

  motor_r->run(BACKWARD);
  motor_l->run(FORWARD);

  
  delay(2000);

  return;
  }

}
return;
}
