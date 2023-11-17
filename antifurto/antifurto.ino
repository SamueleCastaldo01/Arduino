#include <Servo.h>
#include <NewPing.h>

#define pin_trigger 11
#define pin_echo 12
#define massimoL 100

int buzzer= 10;
int soglia=23;
int servo= 9;
int rotazione=0;

NewPing sonar(pin_trigger, pin_echo,massimoL);
Servo Mioservo;

void setup() {
Serial.begin(9600);
pinMode(buzzer,OUTPUT);
Mioservo.attach(servo);

}

void loop() {
float lettura=sonar.ping_cm();
Serial.println(lettura);
delay(50);

if (lettura<soglia && lettura>0) {
  Serial.print("funziona");
  rotazione=90;
Mioservo.write(rotazione);

for (int i=0; i<5; i++){
 digitalWrite(buzzer, HIGH);
  delay (1000);
   digitalWrite(buzzer, LOW);
  delay (1000);
}
}

}
