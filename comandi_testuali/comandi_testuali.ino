char c;
String stringa;
int comando= 0;

void setup() {
Serial.begin(9600);
pinMode(13, OUTPUT);
}

void loop() {
 /*if (Serial.available() >0) 
  {
    char mess =Serial.read();
    if ( mess =='1') {
    Serial.println("ho ricevuto 1");
    digitalWrite(13,HIGH);
    }
    if ( mess =='0'){
    Serial.println("ho ricevuto 0"); 
    digitalWrite(13,LOW);
    }
  }*/
if(Serial.available()){
  stringa="";
  do{
    if(Serial.available()) {
   c=Serial.read();
   stringa+=c; 
    }
  }while(c !='\n');
  Serial.print(stringa);
  
}
}
