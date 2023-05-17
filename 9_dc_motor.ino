// Arduino Motor

#include <AFMotor.h>

AF_DCMotor motor(4);

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop()
{
    // put your main code here, to run repeatedly:
    motor.setSpeed(500);
    motor.run(FORWARD);
    Serial.println("Running forward");
    delay(2000);
    motor.run(RELEASE);
    Serial.println("Stopping");
    delay(1000);
    motor.run(BACKWARD);
    Serial.println("Running backward");
    delay(2000);
    motor.run(RELEASE);
    Serial.println("Stopping");
    delay(1000);
}
