#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600);
}

void loop() {
int t = dht.readTemperature();
int h = dht.readHumidity();
Serial.print("temperatura: ");
Serial.println(t);
Serial.print("umidita': ");
Serial.println(h);
delay(1000);
}
