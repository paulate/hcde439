/*
  Fade - blue, then red

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Fade/
*/

int led = 9;         // the PWM pin the LED is attached to
int led1 = 10;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by
int curLed = led; // current LED, intitialized to pin 9
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(curLed, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  // print out the brightness:
  Serial.println(brightness);
  // switch between the 2 leds every time the brightness reaches 0
  if (brightness <= 0) {
    if (curLed == led) {
      curLed = led1;
    } else {
      curLed = led;
    }
  }
  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
