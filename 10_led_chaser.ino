// LED Chaser Project

int potval;
int const potpin = A0;
int bsped;
int pins[] = { 3, 4, 6, 10, 13 };
int track = 0;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(2, INPUT);
}

void loop()
{
    if (digitalRead(2) == LOW) {
        potval = analogRead(potpin);
        bsped = map(potval, 0, 1023, 200, 1000);
        digitalWrite(pins[track], LOW);
        if (track == 4) {
            track = 0;
            digitalWrite(pins[track], HIGH);
        } else {
            digitalWrite(pins[track + 1], HIGH);
            track++;
        }
        Serial.print("Forward, ");
        Serial.println(String(bsped) + "ms intervals");
        /*Serial.print(String(track) + ", ");
        Serial.println(1);*/
        delay(bsped);
    }

    else {
        potval = analogRead(potpin);
        bsped = map(potval, 0, 1023, 200, 1000);
        digitalWrite(pins[track], LOW);
        if (track == 0) {
            track = 4;
            digitalWrite(pins[track], HIGH);
        } else {
            digitalWrite(pins[track - 1], HIGH);
            track--;
        }
        Serial.print("Backwards, ");
        Serial.println(String(bsped) + "ms intervals");
        /*Serial.print(String(track) + ", ");
        Serial.println(0);*/
        delay(bsped);
    }

    /*potval=analogRead(potpin);
    bsped=map(potval,0,1023,10,300);
    Serial.println(bsped);
    digitalWrite(4,HIGH);
    digitalWrite(3,LOW);
    delay(bsped);

    potval=analogRead(potpin);
    bsped=map(potval,0,1023,10,300);
    Serial.println(bsped);
    digitalWrite(6,HIGH);
    digitalWrite(4,LOW);
    delay(bsped);

    potval=analogRead(potpin);
    bsped=map(potval,0,1023,10,300);
    Serial.println(bsped);
    digitalWrite(10,HIGH);
    digitalWrite(6,LOW);
    delay(bsped);

    potval=analogRead(potpin);
    bsped=map(potval,0,1023,10,300);
    Serial.println(bsped);
    digitalWrite(13,HIGH);
    digitalWrite(10,LOW);
    delay(bsped);

    potval=analogRead(potpin);
    bsped=map(potval,0,1023,10,300);
    Serial.println(bsped);
    digitalWrite(3,HIGH);
    digitalWrite(13,LOW);
    delay(bsped);*/
}
