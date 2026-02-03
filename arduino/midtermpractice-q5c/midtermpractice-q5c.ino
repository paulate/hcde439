
const int buttonPin = 2;
const int tempPin = A0;
const int whiteLED = 6;
const int RGBred = 9;
const int RGBblue = 11;
int tempValue = 0;
int redBrightness = 0;
int blueBrightness = 0;
int buttonCount = 0;
int buttonValue = 0;
int prevButtonValue = 0; 

void setup() {
  // put your setup code here, to run once:
pinMode(buttonPin, INPUT);
pinMode(tempPin, INPUT);
pinMode(whiteLED, OUTPUT);
pinMode(RGBred, OUTPUT);
pinMode(RGBblue, OUTPUT);
}

void allOff() {
  for (int i = 0; i < 14; i ++) {
    digitalWrite(i, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  tempValue = analogRead(tempPin);
  tempValue = constrain(tempValue, 323, 701);
  redBrightness = map(tempValue, 323,701,0,255);
  blueBrightness = map(tempValue, 323,701,255,0);

  buttonValue = digitalRead(buttonPin);
  if (buttonValue != prevButtonValue && buttonValue == 1) {
    buttonCount++;
  }
  if (buttonCount % 3 == 0) { 
    allOff(); // using a function instead of writing LOW to all the LEDs as seen below
    // digitalWrite(whiteLED,LOW);
    // digitalWrite(RGBred,LOW);
    // digitalWrite(RGBblue,LOW);
  } else if (buttonCount % 3 == 1 ) {
    analogWrite(RGBred,redBrightness);
    analogWrite(RGBblue,blueBrightness);
    digitalWrite(whiteLED, HIGH);
  } else {
    analogWrite(RGBred,redBrightness);
    analogWrite(RGBblue,blueBrightness);
    digitalWrite(whiteLED, LOW);      
    }
  prevButtonValue = buttonValue;
}

