#include <IRremote.h>
#include <IRremoteInt.h>
int receiver = 8; // pin 1 of IR receiver to Arduino digital pin 
IRrecv irrecv(receiver); // create instance of 'irrecv'
decode_results results;
#include <Servo.h>

int triggerPort = 11;
int echoPort = 12;
#define ledrosso 7
#define ledverde 6
int buzzer= 10;
int servo= 9;
Servo Mioservo;
int n =1;
long r;


void ultrasuono () {
  digitalWrite( triggerPort, LOW );
//invia un impulso di 10microsec su trigger
digitalWrite( triggerPort, HIGH );
delayMicroseconds( 10 );
digitalWrite( triggerPort, LOW );
long duration = pulseIn( echoPort, HIGH );
 r = 0.034 * duration / 2;

Serial.print( "distanza: " );
if( duration > 38000 ) Serial.println( "fuori portata");
else { Serial.print( r ); Serial.println( "cm" );}
}

void setup() {
pinMode (ledverde, OUTPUT);  
pinMode( triggerPort, OUTPUT );
pinMode( echoPort, INPUT );
Serial.begin( 9600 );
irrecv.enableIRIn(); // Start the receiver
pinMode(buzzer,OUTPUT);
Mioservo.attach(servo);
Mioservo.write(0);
ultrasuono();
delay(500);
Serial.println("Accendi l'antifurto da telecomando");

}



void loop() {
  const long soglia= r;

   digitalWrite(ledverde,LOW);
    analogWrite(ledrosso,220);
  //telecomando ir
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
  
    irrecv.resume();// receive the next value
  }
   if (results.value == 0xFFA25D) {
analogWrite(ledverde,255);
  analogWrite(ledrosso,0);
  
  do{
//porta bassa l'uscita del trigger
ultrasuono();


//funziono
if (r< soglia-2) {
  // Mioservo.write(90);
  Serial.println("funziona");
//allarme buzzer
for (int i=0; i<3; i++){
 digitalWrite(buzzer, HIGH);
  delay (1000);
   digitalWrite(buzzer, LOW);
  delay (750);
} //for
}
       //telecomando
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
  
    irrecv.resume();// receive the next value
  }
} while (results.value != 0xFF6897);
Serial.println("Accendi l'antifurto da telecomando");
}
}
