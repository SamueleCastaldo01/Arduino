void setup() {
  Serial.begin(115200);
 pinMode (13, OUTPUT) ;
 digitalWrite(13, LOW);
}

void loop() {
  if (Serial.available())
  {
    char a = Serial.read();
    delay(100);
   Serial.write("funziona");

     if (a =='h') {
 digitalWrite(13, HIGH);
  delay(100);
 }
      if (a =='l') {
 digitalWrite(13, LOW);
  delay(100);
 }

  }

delay(50);
}
