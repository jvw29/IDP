int trigPin = 10;
int echoPin = 11;

bool ultrasonic(void) {

  int duration;
  int distance;
  
  digitalWrite(trigPin, LOW);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.034/2;

  if (distance > 250 || distance <= 10) {

    return true;
  }
  
  else {
    
    return false;
  }
  
}
