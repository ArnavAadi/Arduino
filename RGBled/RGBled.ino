int redPin = 3;
int bluePin = 6;
int greenPin = 5;
int buttonPin = 2;
int mode = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);
pinMode(redPin,OUTPUT);
pinMode(buttonPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(buttonPin) == HIGH){
  mode = mode+1;
}
if (mode == 0){
  analogWrite(redPin,255);
  analogWrite(greenPin,255);
  analogWrite(bluePin,255);
}else if (mode == 1){
  analogWrite(redPin,255);
  analogWrite(greenPin,0);
  analogWrite(bluePin,0);
}
else if (mode == 2){
  analogWrite(redPin,0);
  analogWrite(greenPin,0);
  analogWrite(bluePin,255);
}
else if (mode == 3){
  analogWrite(redPin,0);
  analogWrite(greenPin,255);
  analogWrite(bluePin,0);
}
else if (mode == 4){
  analogWrite(redPin,255);
  analogWrite(greenPin,255);
  analogWrite(bluePin,0);
}
else if (mode == 5){
  analogWrite(redPin,255);
  analogWrite(greenPin,0);
  analogWrite(bluePin,255);
}
else if (mode == 6){
  analogWrite(redPin,0);
  analogWrite(greenPin,255);
  analogWrite(bluePin,255);
}
else {
  analogWrite(redPin,0);
  analogWrite(greenPin,0);
  analogWrite(bluePin,0);
  mode = 0;
}

}