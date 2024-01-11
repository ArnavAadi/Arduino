void setup() {
  // put your setup code here, to run once:
pinMode(A4, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(analogRead(A4));
}
