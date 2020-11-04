
int val, oldPosition, newPosition;
int photoInt = A0

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(photoInt)
Serial.println(val);


}
