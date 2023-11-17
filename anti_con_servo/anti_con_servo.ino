
#include <Servo.h>
#include <NewPing.h>


#define pin_trigger 11
#define pin_echo 12
#define massimoL 100
#define ledverde 7

int buzzer= 10;
int soglia=23;
int servo= 9;
char mess;
int n=1;

NewPing sonar(pin_trigger, pin_echo,massimoL);
Servo Mioservo;

void setup() {
Serial.begin(9600);
pinMode(buzzer,OUTPUT);
pinMode(ledverde,OUTPUT);
Mioservo.attach(servo);
Mioservo.write(0);
Serial.println("inserisci 'a' per attivare l'antifurto e 'b' per spegnere");
}

void loop() {
   digitalWrite(ledverde,LOW);
  //comando testuale
 if (Serial.available() ) 
  {
    mess =Serial.read();
   Serial.println(mess);}
   
   //antifurto attivo
 if (mess== 'a') {
 digitalWrite(ledverde,HIGH);
  do{
float lettura=sonar.ping_cm();
Serial.println(lettura);
delay(50);

 if (Serial.available() ) 
  {
    mess =Serial.read();}

//allarme ultrasuoni attivo
if (lettura<soglia && lettura>0) {
  Serial.print("funziona");
      //chiusura della porta
 Mioservo.write(90);

//allarme buzzer
for (int i=0; i<3; i++){
 digitalWrite(buzzer, HIGH);
  delay (1000);
   digitalWrite(buzzer, LOW);
  delay (750);
} //for
} //if
} while (mess !='b');
Serial.println("inserisci 'a' per attivare l'antifurto e 'b' per spegnere");
 } 
 }
