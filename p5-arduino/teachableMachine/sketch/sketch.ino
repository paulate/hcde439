void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int val = Serial.parseInt();
    if (Serial.read() == '\n') {
      digitalWrite(7, LOW);
      digitalWrite(6, LOW);

      if (val == 1) {
        digitalWrite(7, HIGH);
      } else if (val == 2) {
        digitalWrite(7, HIGH);
        digitalWrite(6, HIGH);
      }
    }
  }
}
