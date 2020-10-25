#include <Arduino_APDS9960.h>
#include "ir_sensor_bool.h"
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  while (!Serial);

  if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960 sensor!");
  }

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDR, OUTPUT);

  digitalWrite(LEDR, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  /*if (APDS.proximityAvailable()) {
    // read the proximity
    // - 0   => close
    // - 255 => far
    // - -1  => error
    int proximity = APDS.readProximity();

    Serial.println(proximity);

    if (0 <= proximity && proximity <= 240) {

      digitalWrite(LEDR, LOW);
    }

    else {

      digitalWrite(LEDR, HIGH);
    }
  }*/
      
  //Serial.println(distance_from_obstacle);
  if (obstacle_detector()) {

    digitalWrite(LEDR, LOW);
  }

  else {

    digitalWrite(LEDR,HIGH);
  }
  delay(100);
}
