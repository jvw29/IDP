#include <Servo.h>

Servo servo;

int pos = 180;
void setup() {
  // put your setup code here, to run once:
servo.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:

pos = 160;
for (pos = pos; pos >= 0; pos--) { // goes from 180 degrees to 0 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);     
 
}
}
