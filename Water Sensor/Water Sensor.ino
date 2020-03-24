/*
 Name:		Water_Sensor.ino
 Created:	3/22/2020 4:26:36 PM
 Author:	Benny
*/

/*
Reads the value from a Makerfactory moisture sensor and shows the value on an LCD 1602
*/

#include <LiquidCrystal.h>;


int readPin = A0;
int ledPin = 13;
int sensorValue = 0;
int cursorValue = 0;

String valueString;

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

String message = "Sensor value: ";


// the setup function runs once when you press reset or power the board
void setup() {
        //pinMode(ledPin, OUTPUT);
        //digitalWrite(ledPin, HIGH);
        lcd.begin(16, 2);
}

// the loop function runs over and over again until power down or reset
void loop() {

    //set the cursor to column 15, line 0
    lcd.setCursor(15, 0);

    //read the current value from the moisture sensor
    sensorValue = analogRead(readPin);

    //convert value to string for displaying on lcd
    valueString = String(sensorValue);

    //print to the lcd
    //initial message
    for (int positionCounter1 = 0; positionCounter1 < message.length(); positionCounter1++)
    {
        lcd.scrollDisplayLeft();  //Scrolls the contents of the display one space to the left.
        lcd.print(message[positionCounter1]);  // Print a message to the LCD.
        delay(500);
    }

    lcd.scrollDisplayLeft();

    //print sensor value
    for (int positionCounter2 = 0; positionCounter2 < valueString.length(); positionCounter2++)
    {
        cursorValue = 15 + positionCounter2;
        lcd.setCursor(cursorValue, 1);
        lcd.print(valueString[positionCounter2]);
        delay(500);
    }

    
    //wait 1 miunte to read the next value
    delay(1800000);

    lcd.clear();
    
}
