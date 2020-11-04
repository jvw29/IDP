//Pins required for LDR
int LEDpin = 5;
int LDRpin = A3;

bool LDR(void) {

   int colour, reading, sum;
  float mean, thresh_low;
//Controls strength of signal from pin

  int i = 0;

///  digitalWrite(LEDpin, HIGH);

  sum = 0;
  mean = 0;
  thresh_low = 0;
  
///  Move robot back so block will not affect readings


  motor_l->run(FORWARD);
  motor_r->run(FORWARD);
  
  motor_l->setSpeed(150);
  motor_r->setSpeed(150);

  

  Serial.println("Move backward");
  delay(1000);

  motor_l->setSpeed(0);
  motor_r->setSpeed(0);

//  Takes ambient readings of LDR
  for (i = 0; i <= 20; i+=1) {
  
    reading = analogRead(LDRpin); 

//    Serial.println(reading);
    sum += reading;
//    Serial.println(sum);
  }

//  Find average reading and incopororate error reading, any higher means the block is blue
  mean = sum/21;

  thresh_low = mean * 0.96;

  Serial.print("Threshold is");
  Serial.print(thresh_low);
  Serial.println();

//  delay(5000);
//  Moves towards block to take reading
  motor_l->setSpeed(150);
  motor_r->setSpeed(150);

  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);

  Serial.println("Move forward");
  delay(1200);

  motor_l->setSpeed(0);
  motor_r->setSpeed(0);

  delay(1000);
  colour = analogRead(LDRpin);
  delay(500);
  Serial.print("reading is");
  Serial.print(colour);
  Serial.println();
  
//If the fruit is blue (unripe), the signal from the amplifier will be high
  if (colour <= thresh_low) {

    Serial.println("Red");

    digitalWrite(LEDpin,LOW);
    return true;
  }

//If the fruit is red (ripe), the signal from the amplifier will bev low) 
  else {

    Serial.println("Blue");

    return false;
//    digitalWrite(LEDpin,LOW);

}
}
