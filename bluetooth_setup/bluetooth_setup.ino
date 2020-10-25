void setup() {
  // put your setup code here, to run once:

pinMode(NINA_RESETN, OUTPUT);         
     digitalWrite(NINA_RESETN, LOW);
     
     Serial.begin(115200);
     SerialNina.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

if (Serial.available()) {
  SerialNina.write(Serial.read());}
  if (SerialNina.available()) {
  Serial.write(SerialNina.read());}

}
