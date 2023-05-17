// LED Blinker, LED brightness is set with AnalogWrite

int redLEDPin = 9; // Declare redLEDPin an int, and set to pin 9
int yellowLEDPin = 10; // Declare yellowLEDPin an int, and set to pin 10
int redOnTime = 250; // Declare redOnTime an int, and set to 250 mseconds
int redOffTime = 250; // Declare redOffTime an int, and set to 250
int yellowOnTime = 250; // Declare yellowOnTime an int, and set to 250
int yellowOffTime = 250; // Declare yellowOffTime an int, and set to 250
int numYellow; // Number of times to blink yellow LED
int numRed; // Number of times to blink red LED
String redMessage = "The Red LED is Blinking"; // Declaring a String Variable
String yellowMessage = "The Yellow LED is Blinking"; // Declaring a String Variable
float rbright;
float ybright;

void setup()
{
    Serial.begin(9600); // Turn on the Serial Port
    pinMode(redLEDPin, OUTPUT); // Tell Arduino that redLEDPin is an output pin
    pinMode(yellowLEDPin, OUTPUT); // Tell Arduino that yellowLEDPin is an output pin
}

void loop()
{
    Serial.println("How many times do you want the red LED to blink? ");
    while (Serial.available() == 0) { }
    numRed = Serial.parseInt();
    while (Serial.available() > 0) {
        Serial.read();
    }
    Serial.println("How bright do you want the red LED to be from 0-5? ");
    while (Serial.available() == 0) { }
    rbright = Serial.parseFloat();
    while (Serial.available() > 0) {
        Serial.read();
    }

    Serial.println("Red LED blinks " + String(numRed) + " times with brightness of " + String(rbright));
    Serial.println(" ");

    Serial.println("How many times do you want the yellow LED to blink?");
    while (Serial.available() == 0) { }
    numYellow = Serial.parseInt();
    while (Serial.available() > 0) {
        Serial.read();
    }
    Serial.println("How bright do you want the yellow LED to be from 0-5? ");
    while (Serial.available() == 0) { }
    ybright = Serial.parseFloat();
    while (Serial.available() > 0) {
        Serial.read();
    }

    Serial.println("Yellow LED blinks " + String(numYellow) + " times with brightness of " + String(ybright));
    Serial.println(" ");

    Serial.println(redMessage);
    for (int j = 1; j <= numRed; j = j + 1) { // Start our for loop
        Serial.print("   You are on Blink #: ");
        Serial.println(j);
        analogWrite(redLEDPin, rbright * 51); // Turn red LED on
        delay(redOnTime); // Leave on for redOnTime
        analogWrite(redLEDPin, 0); // Turn red LED off
        delay(redOffTime); // Leave off for redOffTime
    }
    Serial.println(" ");

    Serial.println(yellowMessage);
    for (int j = 1; j <= numYellow; j = j + 1) { // Start our for loop
        Serial.print("   You are on Blink #: ");
        Serial.println(j);
        analogWrite(yellowLEDPin, ybright * 51); // Turn yellow LED on
        delay(yellowOnTime); // Leave on for yellowOnTime
        analogWrite(yellowLEDPin, 0); // Turn yellow LED off
        delay(yellowOffTime); // Leave off for yellowOffTime
    }
    Serial.println(" ");
}
