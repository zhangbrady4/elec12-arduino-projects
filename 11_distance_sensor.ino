// Distance sensor using an Ultrasonic Sensor

int trig = 11;
int echo = 13;
float ping;
float dist;
float sspeed;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    digitalWrite(trig, LOW);
    delayMicroseconds(2000);
    digitalWrite(trig, HIGH);
    delayMicroseconds(15);
    digitalWrite(trig, LOW);
    delayMicroseconds(10);

    ping = pulseIn(echo, HIGH);
    ping = ping / 1000000;
    ping = ping / 2;
    dist = ping * 343;
    Serial.println(dist);
    delay(100);
}
