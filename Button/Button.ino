/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int buzzerPin =  6;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 1500;    // the debounce time; increase if the output flickers
int buzzerState = LOW;

void setup()
{
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  // initialize the buzzer pin as an output:
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  // read the state of the pushbutton value:
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState)
  {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (reading != buttonState)
    {
      buttonState = reading;
      if (buttonState == HIGH)
      {
        buzzerState = HIGH;
      }
      else
      {
        buzzerState = LOW;
      }
    }
  }
  lastButtonState = reading;

  if (buzzerState == HIGH)
  { // turn LED and buzzer on:
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(500);

    // turn LED and buzzer off:
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(300);
  }
  else
  {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
}
