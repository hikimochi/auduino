void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  for (int i = 9; i < 14; i++) { 
    digitalWrite(i, HIGH);
    delay(2000);
    digitalWrite(i, LOW);
    delay(2000);
  }
}
