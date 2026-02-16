// make the DC motor go clockwise for half a second, then counterclockwise for another half second. Loop! 
// uses L293D Chip
void setup() {
  pinMode(7, OUTPUT); // connected to pin 1 on L293D
  pinMode(6, OUTPUT); // connected to pin 2 L293D
  pinMode(5, OUTPUT); // connected to pin 7 on L293D
  Serial.begin(9600);
  digitalWrite(7,HIGH); // "enable the first motor driver all the time!"
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5,LOW); // keep LOW so that pin 2 is easily read as HIGH
  delay(10); //a slight delay to tell the motor to stop completely (both low)
  digitalWrite(6,HIGH); // tell motor to go in one direction e.g. clockwise
  delay(500);
  digitalWrite(6,LOW); // keep LOW so that pin 7 is read as HIGH
  delay(10); //a slight delay to tell the motor to stop completely (both low)
  digitalWrite(5,HIGH); // tell motor to go in the other direction e.g. CCW. 
  delay(500);
}
