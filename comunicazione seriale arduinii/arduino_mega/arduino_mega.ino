void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);

}

void loop() {
  if (Serial.available())
  {
  char a = Serial.read();
  delay(10);
  Serial1.write(a);

  /*if( a =='n'){
   Serial1.write('h');
     }*/

  //comunicazione
  while (!Serial1.available())
  {}
  char b = Serial1.read();
  Serial.print("l'arduino uno ha risposto ");
  Serial.println(b);
   }
delay (100);
}
