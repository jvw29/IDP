int trigPin = 13;
int echoPin = 12;

bool ultrasonic(void) {
  int sum = 0;
  int duration;
  int distance;
  float mean = 0;

  for (int i =0; i<=3; i++) {
  digitalWrite(trigPin, LOW);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.034/2;

//  Serial.println(distance);

  sum += distance;
  }

  mean = sum/4;

  Serial.println(mean);
  if (3 <= mean && mean <= 12) {

    return true;
  }
  
  else {
    
    return false;
  }
  
}
