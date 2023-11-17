int buzzer= 10;

void setup() {
pinMode(buzzer,OUTPUT);

}

void loop() {
for (int i=0; i<10; i++){
  delay (1000);
  tone (buzzer,440,1000); 
  delay (2000);
}
}
