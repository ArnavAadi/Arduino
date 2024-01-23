#define led1 2
#define led2 3
#define led3 4
#define buttonPin 8

long timeNow = millis();
long timeBefore1 = 0;
long timeBefore2 = 0;
long buttonDelay = 50;
byte buttonState = LOW;
byte ledState = LOW;
int lastButton = 2;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  timeNow = millis();

  if (timeNow - timeBefore1 > buttonDelay) {
      byte newButtonState = digitalRead(buttonPin);
      if (newButtonState != buttonState) {
        buttonState = newButtonState;
        if (buttonState == HIGH) {
          Serial.println("press");
            if (lastButton == 2) {
              digitalWrite(3, HIGH);
              digitalWrite(2, LOW);
              lastButton = 3;
            }else {
              digitalWrite(2, HIGH);
              digitalWrite(3, LOW);
              lastButton = 2;
            }
        }
        timeBefore1 = timeNow;
  }}
  if (timeNow - timeBefore2 > 1000) {
    timeBefore2 = timeNow;
    if (ledState == HIGH) {
      digitalWrite(led3, LOW);
      ledState = LOW;
    } else {
      digitalWrite(led3, HIGH);
      ledState = HIGH;
    }
  }
}
