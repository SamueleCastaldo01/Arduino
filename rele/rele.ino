const int relayPin = 7;          
char c;
String stringa;

void setup()
{
  pinMode(relayPin, OUTPUT);   
  Serial.begin(9600);
}

void loop() {
 stringa= "";
  do {
    if (Serial.available()) {
    c= Serial.read();
    if(c != '\n')
    stringa+=c;
    }
  }while (c != '\n');
  
  if (stringa == "spegni")
  digitalWrite(relayPin, HIGH); //drive relay closure conduction
           
   if (stringa == "accendi")
  digitalWrite(relayPin, LOW);  //drive the relay is closed off

  //Serial.println(stringa);
}
