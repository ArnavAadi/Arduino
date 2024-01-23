#include <Servo.h>

#define echoPin 3
#define triggerPin 4
#define servoPin 5

Servo Servo1;

long prevTimeOpen;
long prevTime = 0;
volatile long timeStart;
volatile long timeEnd;
volatile bool dataAvailable = false;
volatile double prevDistance = 400;

void echoInterrupt() {
  if (digitalRead(echoPin) == HIGH) {
    timeStart = micros();
  } else {
    timeEnd = micros();
    dataAvailable = true;
  }
}

void triggerUltrasonicSensor() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
}

double getDistance() {
  // long timebefore = micros();
  double distanceMicros = timeEnd - timeStart;
  // long timeafter = micros();
  double distance = distanceMicros / 58;
  // Serial.println("DURATION: ");
  // Serial.println(timeafter-timebefore);
  if (distance > 400.0) {
    return prevDistance;
  }
  distance = prevDistance * 0.7 + distance * 0.1;
  prevDistance = distance;
  return distance;
}

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(echoPin), echoInterrupt, CHANGE);
  Servo1.attach(servoPin);
}

void loop() {
  long timeNow = millis();
  if (timeNow - prevTime > 60) {
    prevTime = timeNow;
    triggerUltrasonicSensor();
  }
  if (dataAvailable) {
    dataAvailable = false;
    double distance = getDistance();
    Serial.println(distance);
    if (distance < 20) {
      Servo1.write(180);
      prevTimeOpen = millis();
    } else if (timeNow - prevTimeOpen > 5000) {
      Servo1.write(0);
    }
  }
}