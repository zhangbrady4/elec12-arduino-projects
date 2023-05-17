// LED pattern displayer

int switchstate = 0;

void setup()
{ // put your setup code here, to run once:
    pinMode(2, INPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    switchstate = digitalRead(2);
    if (switchstate == LOW) {
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
    } else {
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        delay(300);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        delay(300);
        digitalWrite(6, LOW);
        digitalWrite(4, HIGH);
    }
}
