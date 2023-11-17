#include <LiquidCrystal.h>
int ledrosso =  7;
char c;
String stringa;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

void setup ()
{
  Serial.begin(9600);
  pinMode (ledrosso, OUTPUT);
  Serial.println("Digita h per accendere il led, l per chiuderlo");
}
void loop ()
{
if(Serial.available()) {

  stringa= "";
  do {
    if (Serial.available()) {
    c= Serial.read();
    if(c != '\n')
    stringa+=c;
    }
  }while (c != '\n');
  
     if (stringa == "H")
  {
    digitalWrite (ledrosso, HIGH);

  }
  if (stringa == "L")
  {
    digitalWrite (ledrosso, LOW);
  }
    if ( stringa == "h")
  {
    digitalWrite (ledrosso, HIGH);
  }
  if (stringa == "l")
  {
    digitalWrite (ledrosso, LOW);
  }
  
   Serial.print(stringa);
    lcd.begin(16, 2);  
     lcd.print(stringa );

  }
}
