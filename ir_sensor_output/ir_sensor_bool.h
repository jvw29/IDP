#include <Arduino_APDS9960.h>

bool obstacle_detector(void) {

  if (APDS.proximityAvailable()) {
    // read the proximity
    // - 0   => close
    // - 255 => far
    // - -1  => error
    int proximity = APDS.readProximity();

    Serial.println(proximity);

    if (0 <= proximity && proximity <= 240) {

      return true;

      delay(200);
    }

    else if (241 <= proximity && proximity <= 255) {

      return false;
    }

    else {

      Serial.println("Error: number returned is outside of range of possible values");
      return false;
    }
    
    }

   else {

    Serial.println("Error: sensor not initialised");
    return false;
   }

   
}
