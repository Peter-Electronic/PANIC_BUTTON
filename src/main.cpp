#include <Arduino.h>
/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = D2;     // the number of the pushbutton pin
//const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
 
#define LED_GPIO   D3
#define PWM1_Ch    0
#define PWM1_Res   8
#define PWM1_Freq  1000

int PWM1_DutyCycle = 0;
void setup() {
  // initialize the LED pin as an output:
  pinMode(buttonPin, INPUT_PULLUP);
  ledcSetup(PWM1_Ch, PWM1_Freq, PWM1_Res);
  pinMode(LED_BUILTIN, OUTPUT);
    ledcAttachPin(LED_GPIO, PWM1_Ch);
	Serial.begin(115200);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(LED_BUILTIN,LOW);
    ledcWrite(PWM1_Ch, 0);
    Serial.println("OFF");
  } else {
    // turn LED off:
    ledcWrite(PWM1_Ch, 100);
    digitalWrite(LED_BUILTIN,HIGH);
    Serial.println("ON");

  }
}
