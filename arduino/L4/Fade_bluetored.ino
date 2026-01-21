/*
  Fade - blue to red

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Fade/
*/

int led = 9;         // the PWM pin the first LED is attached to
int led1 = 10;         // the PWM pin the second LED is attached to
int brightness = 255;  // initial value, how bright the LED is
int fadeAmount = -5;  // how many points to fade the LED by
int brightness1 = 0;  // initial value, how bright the second LED is
int fadeAmount1 = 5; // how many points to fade the LED by
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // declare pin 9 & 10 to be an output:
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9 & 10:
  analogWrite(led, brightness);
  analogWrite(led1, brightness1);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  brightness1 = brightness1 + fadeAmount1;
  // print out the brightness:
  Serial.println(brightness);
  Serial.println(brightness1);
  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
    if (brightness1 <= 0 || brightness1 >= 255) {
    fadeAmount1 = -fadeAmount1;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(1000);
}
