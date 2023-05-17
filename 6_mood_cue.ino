// Mood Cue (Servo motor)

#include <Servo.h>
Servo Myservo;
int const potpin = A0;
int potval;
int angle;

void setup()
{
    // put your setup code here, to run once:
    Myservo.attach(9);
    Serial.begin(9600);
}

void loop()
{
    // put your main code here, to run repeatedly:
    potval = analogRead(potpin);
    Serial.print("Potentiometer value: " + String(potval));
    angle = map(potval, 0, 1023, 35, 179);
    Serial.println(", Angle: " + String(angle));
    Myservo.write(angle);
}
