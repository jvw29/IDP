int interrupter_pin = A3;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int value = analogRead(interupter_pin);

Serial.println(value);
delay(250);
}
