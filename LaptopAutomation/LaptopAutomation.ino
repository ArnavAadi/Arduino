#define echoPin 3
#define triggerPin 4

long prevTime = 0;
volatile long timeStart;
volatile long timeEnd;
volatile bool dataAvailable = false;


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
  return distance;
}

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(echoPin), echoInterrupt, CHANGE);
}

void loop() {
  long timeNow = millis();
  if (timeNow - prevTime > 100) {
    prevTime = timeNow;
    triggerUltrasonicSensor();
  }
  if (dataAvailable) {
    dataAvailable = false;
    double distance = getDistance();
    if (distance < 20) {
      Serial.println("Volume up");
    }
  }
}
