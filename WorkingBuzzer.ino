/*
  To learn more about this code check out the readME.adoc
*/
// Headers
// Variables
int buzPin = 8;
int potVal;
int potRead = A0;
int dT = 5;
int dT1 = 25;
int dT2 = 50;
int dT3 = 75;
int dT4 = 100;

// Function
int playNotes(int val) {
  if(val <= 100){
    digitalWrite(buzPin, HIGH);
    delay(dT4);
    digitalWrite(buzPin, LOW);
    Serial.println(potVal);
  } else if (val > 101 && val <= 250) {
    digitalWrite(buzPin, HIGH);
    delay(dT3);
    digitalWrite(buzPin, LOW);
    Serial.println(potVal);
  } else if (val > 251 && val <= 500) {
    digitalWrite(buzPin, HIGH);
    delay(dT2);
    digitalWrite(buzPin, LOW);
    Serial.println(potVal);
  } else if (val > 501 && val <= 750) {
    digitalWrite(buzPin, HIGH);
    delay(dT1);
    digitalWrite(buzPin, LOW);
    Serial.println(potVal);
  } else {
    digitalWrite(buzPin, HIGH);
    delay(dT);
    digitalWrite(buzPin, LOW);
    Serial.println(potVal);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial){
    ;
  }
  pinMode(buzPin, OUTPUT);
  pinMode(potRead, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potRead);
  playNotes(potVal);
  Serial.println(potVal);
}
