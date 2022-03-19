#define STEP    D2
#define DIR     D3
#define ENABLE  D4

int stepPerRevolution = 200;

void setup() {
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  
  digitalWrite(ENABLE, LOW);
}

void loop() {
  digitalWrite(DIR, HIGH);
  for (int x = 0; x <= stepPerRevolution; x++) {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP, LOW);
    delayMicroseconds(1000);
  }
  delay(1000);

  digitalWrite(DIR, LOW);
  for (int x = 0; x <= stepPerRevolution; x++) {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP, LOW);
    delayMicroseconds(1000);
  }
  delay(1000);
}
