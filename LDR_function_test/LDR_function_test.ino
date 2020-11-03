//int LEDpin = 5;
int LDRpin = A4;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int colour, reading, sum;
  float mean, thresh_high;
//Controls strength of signal from pin

  int i = 0;

  digitalWrite(LEDpin, HIGH);

  sum = 0;
  mean = 0;
  thresh_high = 0;
  
//  Move robot back so block will not affect readings
  /*motor_l->setSpeed(150);
  motor_r->setSpeed(150);

  motor_l->run(FORWARD);
  motor_r->run(FORWARD);

  delay(1000);

  motor_l->setSpeed(0);
  motor_r->setSpeed(0);*/

//  Takes ambient readings of LDR
  for (i = 0; i <= 100; i++) {
  
    reading = analogRead(LDRpin); 

    sum += reading;
  }

//  Find average reading and incopororate error reading, any higher means the block is blue
  mean = sum/100;

  thresh_high = mean * 1.1;

  Serial.print("Threshold is");
  Serial.print(thresh_high);
  Serial.println();
  
//  Moves towards block to take reading
  /*motor_l->setSpeed(150);
  motor_r->setSpeed(150);

  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);

  delay(1000);

  motor_l->setSpeed(0);
  motor_r->setSpeed(0);*/

  colour = analogRead(LDRpin);
//If the fruit is blue (unripe), the signal from the amplifier will be high
  if (colour >= thresh_high) {

    Serial.println("Blue");

//    digitalWrite(LEDpin,LOW);
    return false;
  }

//If the fruit is red (ripe), the signal from the amplifier will bev low) 
  else {

    Serial.println("Red");

//    digitalWrite(LEDpin,LOW);
}
