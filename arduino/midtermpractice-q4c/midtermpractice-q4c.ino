 int greenPin = 6;
int bluePin = 2;
int Button = 3;
int greenBrightness = 0;
int addBrightness = 1;
int buttonValue = 0;
int t = 400;

void blink(int t){
  if (t < 200){ // made the timing x2 because it was easier to see the blinking. 
    digitalWrite(2, LOW);
  }else if (t >= 200 && t < 400){
	digitalWrite(2, HIGH);
  }else if (t > 400 && t <= 600) {
    digitalWrite(2, LOW);
  }else if ( t > 800) {
	digitalWrite(2, HIGH);
  }
}

void setup()
{
  Serial.begin(9600);
  digitalWrite(bluePin,HIGH);
}

void loop(){
  greenBrightness += addBrightness;
	analogWrite(greenPin, greenBrightness);
  if (greenBrightness >= 255 || greenBrightness < 0){
		addBrightness = -addBrightness;
  }
	buttonValue = digitalRead(Button);
	
	if (buttonValue == 1)  {
		t = 0;
      Serial.println("button");
	}

	blink(t);
  Serial.println(t);
  t++;  // increment t by 1 every time we loop. 
  delay(1); // this ensures that the loop happens once a millisecond. 

};