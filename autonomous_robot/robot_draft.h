
//Label each oin with corresponding ultrasound purppose.
const int trigPin1 = 8;
const int echoPin1 = 9;

const int trigPin2 = 10;
const int echoPin2 = 11;

const int trigPin3 = 12;
const int echoPin3 = 13;

int distance_ahead;

digitalWrite(trigPin1,LOW);
delayMicroseconds(2);

digitalWrite(trigPin1,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1,LOW);

duration_ahead = PulseIn(echoPin1,HIGH);

distance_ahead = duration_ahead*0.034/2;

if (distance_ahead <= 30) {

  int distance_left, distance_right;
  
  digitalWrite(trigPin2,LOW);
  digitalWrite(trigPin3,LOW):
  delayMicroseconds(2);

  digitalWrite(trigPin2,HIGH);
  digitalWrite(trigPin3,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);
  digitalWrite(trigPin3,LOW);

  duration_left = pulseIn(echoPin2,HIGH);
  duration_right = pulseIn(echoPin3,HIGH);

  distance_left = duration_left*0.034/2;
  distance_right = duration_right*0.034/2

  if (distance_right > distance_left) {

    motor1->setSpeed(150);
    motor3->setSpeed(150);
    motor2->setSpeed(0);
    motor4->setSpeed(0);

    motor1->run(FORWARD);
    motor2->run(FORWARD);
    motor3->run(FORWARD);
    motor4->run(FORWARD);
  }

  else {

    motor1->setSpeed(0);
    motor3->setSpeed(0);
    motor2->setSpeed(150);
    motor4->setSpeed(150);

    motor1->run(FORWARD);
    motor2->run(FORWARD);
    motor3->run(FORWARD);
    motor4->run(FORWARD);
  }
}

else {

  motor1->setSpeed(150);
  motor2->setSpeed(150);
  motor3->setSpeed(150);
  motor4->setSpeed(150);

  motor1->run(FORWARD);
  motor2->run(FORWARD);
  motor3->run(FORWARD);
  motor4->run(FORWARD);
}
