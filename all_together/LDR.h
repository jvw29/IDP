//Pins required for LDR
int LEDpin = 5;
int PWMpin = 9;
int colourpin = 7;

bool LDR(void) {

  int PWM_out_level, colour;

//Controls strength of signal from pin
PWM_out_level = 127;

analogWrite(PWMpin, PWM_out_level);

digitalWrite(LEDpin, HIGH);

colour = digitalRead(colourpin);

//If the fruit is blue (unripe), the signal from the amplifier will be high
if (colour == 1) {

  //Serial.println("Blue");

  digitalWrite(LEDpin,LOW);
  return false;
}

//If the fruit is red (ripe), the signal from the amplifier will bev low) 
else if (colour == 0) {

  //Serial.println("Red");

  digitalWrite(LEDpin,LOW);
  return true;
}
}
