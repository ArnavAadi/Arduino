#include "dht.h"
#define dhtpin 7
dht DHT;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
DHT.read11(dhtpin);
Serial.println(DHT.temperature);
Serial.println(DHT.humidity);
delay(1000);
}
