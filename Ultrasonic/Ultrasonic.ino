#define echoPin 3
#define triggerPin 4
#define led1 10
#define led2 11
#define led3 12

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
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
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
    Serial.println(distance);
    if (distance > 100) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    } else if (distance > 15) {
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led3, LOW);
    } else {
      digitalWrite(led3, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
    }
  }
}
