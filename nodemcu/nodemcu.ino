#include <ESP8266WiFi.h> 

const char *SSID = "G7 ThinQ_";
const char *PASSWORD = "biscotto";
const int PORT = 8080;

//inizializzo un nuovo oggetto server della classe WiFiServer 
//passando come argomento la porta su cui si mettera' in ascolto
WiFiServer server(PORT);

const int ledPinRed = D2; 
const int ledPinGreen = D1; 
const int relayPin = D3; 

void startWiFi() {
  Serial.print("Connecting to ");
  Serial.println(SSID);
   
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("WiFi connected");
}

void setup() {
  
  Serial.begin(115200);
  
  delay(25); 
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(relayPin, OUTPUT);

  //mi collego all'hotspot
  startWiFi();

  //avvio il server
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
  digitalWrite(ledPinRed, LOW);
}

void loop() {

  //inizializzo un nuovo oggetto client della classe WiFiClient
  WiFiClient client = server.available();   //NON bloccante

  //entra se un nuovo client si e' connesso
  if(client) {
    String reply = "comando non trovato";
    
    String request = client.readStringUntil('\r');    //la richiesta da parte del client deve contenere "\r\n", timeout di defaul di 1000ms altrimenti setTimeout()
    Serial.println(request);   

     if(request.equals("accendi")) {  
      digitalWrite(ledPinRed, HIGH);   
      digitalWrite(ledPinGreen, HIGH);  
      reply = "led accesi";      
    }

     if(request.equals("spegni")) {  
      digitalWrite(ledPinRed, LOW);   
      digitalWrite(ledPinGreen, LOW);  
      reply = "led accesi";      
    }


    if(request.equals("accendi led rosso")) {  
      digitalWrite(ledPinRed, HIGH);   
      reply = "led rosso acceso";      
    }
    else if(request.equals("spegni led rosso")) {  
      digitalWrite(ledPinRed, LOW);    
      reply = "led rosso spento"; 
    } 
    else if(request.equals("accendi led verde")) {  
      digitalWrite(ledPinGreen, HIGH);   
      reply = "led verde acceso";
    } 
    else if(request.equals("spegni led verde")) {  
      digitalWrite(ledPinGreen, LOW);     
      reply = "led verde spento";  
    }

     else if(request.equals("accendi lampadina")) {  
      digitalWrite(relayPin, HIGH);     
      reply = "lampadina accesa";  
    } 
    else if(request.equals("spegni lampadina")) {  
      digitalWrite(relayPin, HIGH);     
      reply = "lampadina spenta";  
    }
    
    
    client.println(reply);            
    client.stop();
  }
  else {
    delay(500);
  }
}
