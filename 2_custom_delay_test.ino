// (3 LED) blinker with custom delay

int LED1 = 12;
int LED2 = 9;
int LED3 = 2;
int waittime = 1000;
int waittime1 = 500;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    for (int i = 0; i < 5; i++) {
        Serial.println(i);
        digitalWrite(LED1, HIGH);
        delay(2500 - i * 500);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        delay(2500 - i * 500);
        digitalWrite(LED2, LOW);
    }
    Serial.println();

    digitalWrite(LED3, HIGH);
    delay(waittime);
    digitalWrite(LED3, LOW);
}
