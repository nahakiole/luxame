/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

String inputString = "";      // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

int ledblue = 2;         // the PWM pin the LED is attached to
int ledred = 3;
int ledyellow = 4;
int ledgreen = 5;
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
    // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  // declare pin 9 to be an output:
  pinMode(ledblue, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(ledgreen, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  //analogWrite(led, brightness);

  // wait for 30 milliseconds to see the dimming effect
  delay(30);

   if (stringComplete) {
    inputString.trim();  // Remove any whitespace
    if (inputString == "blue 1") {
      digitalWrite(ledblue, HIGH);
    } else if (inputString == "blue 0") {
      digitalWrite(ledblue, LOW);
    } else if (inputString == "red 1") {
      digitalWrite(ledred, HIGH);
    } else if (inputString == "red 0") {
      digitalWrite(ledred, LOW);
    } else if (inputString == "yellow 1") {
      digitalWrite(ledyellow, HIGH);
    } else if (inputString == "yellow 0") {
      digitalWrite(ledyellow, LOW);
    } else if (inputString == "green 1") {
      digitalWrite(ledgreen, HIGH);
    } else if (inputString == "green 0") {
      digitalWrite(ledgreen, LOW);
    }
    Serial.println(inputString);

    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
