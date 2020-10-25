const int trigPinl = 10;
const int echoPinl = 11;

const int trigPinr = 12;
const int echoPinr = 13;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPinl, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPinl, INPUT); // Sets the echoPin as an Input

pinMode(trigPinr, OUTPUT);
pinMode(echoPinr, INPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int distance_ahead_l, distance_ahead_r;
  long duration_l, duration_r;

  digitalWrite(trigPinl,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPinl,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinr,LOW);

  duration_l = pulseIn(echoPinl,HIGH);

  digitalWrite(trigPinr,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPinr,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinr,LOW);
  
  duration_r = pulseIn(echoPinr,HIGH);

  distance_ahead_l = duration_l*0.034/2;
  distance_ahead_r = duration_r*0.034/2;

  Serial.println(distance_ahead_l);
  /*if (distance_ahead_l <= 5) {

    Serial.println("Within range left");
  }
  
  if (distance_ahead_r <= 5) {

    Serial.println("Within range right");
  }*/
  //delay(50);
}
