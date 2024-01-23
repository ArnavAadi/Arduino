#include <EEPROM.h>
#define potPin A1
#define ledPin 3

byte intensity = 255;
int potInput = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    intensity = Serial.parseInt();
    Serial.println(intensity);
    EEPROM.write(0, intensity);
  }
  potInput = analogRead(potPin);
  if (potInput > EEPROM.read(0)) {
    analogWrite(ledPin, EEPROM.read(0));
  } else {
    analogWrite(ledPin, potInput/4);
  }
}
