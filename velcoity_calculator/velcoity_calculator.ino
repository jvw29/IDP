#include <Arduino_LSM9DS1.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  if (!IMU.begin()) {

     Serial.println("Failed to initialise accelerometer")
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  float ax,ay,az,dt, squares;
  double magnitude;
  static float vx,vy,vz;

  //dt = time period of output from accelerometer
  dt = 1/104;
  
  if (IMU.accelerationavailable) {

    IMU.readacceleration(ax,ay,az);
    
    
    // Euler method to calculate velocities
    vx = vx + ax*dt;
    vy = vy + ay*dt;
    vz = vz + az*dt;

    squares = sq(vx) + sq(vy) + sq(vz);
    magnitude = sqrt(squares)

    return magnitude
  }
}
