int LEDpin = 5;
int PWMpin = 9;
int colourpin = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDpin, OUTPUT);
  pinMode(PWMpin, OUTPUT);
  pinMode(colourpin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int PWM_out_level, colour;

//Controls strength of signal from pin
PWM_out_level = 127;

analogWrite(PWMpin, PWM_out_level);

digitalWrite(LEDpin, HIGH);

colour = digitalRead(colourpin);

//If the fruit is blue (unripe), the signal from the amplifier will be high
if (colour == 1) {

  Serial.println("Blue");
}

//If the fruit is red (ripe), the signal from the amplifier will bev low) 
else if (colour == 0) {

  Serial.println("Red");
}
//Delay so it is easier to read the signal monitor.
delay(250);
}
