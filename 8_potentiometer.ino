// Potentiometer controlled LED brightness (AnalogRead)

int potpin = A0;
int potval;
int ledpin = 9;
float vt;
float ledvt;

void setup()
{
    // put your setup code here, to run once:
    pinMode(potpin, INPUT);
    pinMode(ledpin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    // put your main code here, to run repeatedly:
    potval = analogRead(potpin);
    vt = potval / (204.6);
    Serial.println("The voltage is " + String(vt));
    analogWrite(ledpin, vt * 51);
    delay(100);
}
