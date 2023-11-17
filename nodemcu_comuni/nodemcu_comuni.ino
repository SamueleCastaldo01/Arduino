void setup() {
  Serial.begin(115200);


}

void loop() {
   Serial.write('h');
  if (Serial.available())
  {
  char a = Serial.read();
  delay(10);
  Serial.write('h');
  delay(2000);
    Serial.write('l');

  /*if( a =='n'){
   Serial.write('h');
 
  }*/

  //comunicazione
  while (!Serial.available())
  {}
  char b = Serial.read();
  Serial.print("l'arduino uno ha risposto ");
  Serial.println(b);
   }
delay (100);
}
