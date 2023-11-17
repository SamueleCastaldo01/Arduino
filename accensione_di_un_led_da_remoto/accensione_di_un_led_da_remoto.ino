#include <Ethernet.h> //libreria ethernet
#include <SPI.h> //collabora con la libreria ethernet
#include <String.h> //gestione stringhe

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; //indirisso fisico
byte ip[] = {192, 168, 1, 177}; //indirizzo ip locale
byte subnet[] = {255, 255, 255, 0}; //indirizzo subnet
byte gateway[] = {192, 168, 1, 1}; //indirizzo gateway
EthernetServer server(80); //imposto porta protocollo HTTP

int led = 7; //dichiarazione led
String ascoltatore; //dichiarazione stringa

void setup() {
  Ethernet.begin(mac, ip, gateway, subnet); //inizializzazione impostazioni
  pinMode(led, OUTPUT); //impostazione led come output
  ascoltatore=""; //inizializzazione stringa
}

void loop() {
  EthernetClient client = server.available(); //attendo l'arrivo di un client
  
  if (client) { //se c'è il cliente deve..
    
    while(client.connected()) {
      if(client.available()) {
        char c = client.read(); //..leggere i caratteri che invia
        ascoltatore.concat(c); //concatena i caratteri del client
        
        if (c == '\n') { //se arrivo a fine riga
           if(ascoltatore.indexOf("led=1")>0) { //controllo che nell'url ci sia led=1
            digitalWrite(led, HIGH); //se c'è accendo il led
           }
           else {
            digitalWrite(led, LOW); //altrimenti spengo il led
           }
        client.println("HTTP/1.1 200 OK"); //dico al client che è tutt'ok - standard http
        client.println("Content-Type: text/html"); //indico il formato - standard http
        client.println(); //necessario per non buggare 
        client.println("<html>"); //inizio codice html
        client.println("<head><title>Accendi/Spegni led</title> <link rel='shortcut icon' type='image/x-icon' href='http://i44.servimg.com/u/f44/16/84/89/65/23570310.png' /></head>");
        client.println("<body><a href='/?led=1'>Accendi</a> - <a href='/?led=0'>Spegni</a></body");
        client.println("</html>"); //fine codice html
        client.stop(); //stop richieste dal client
        ascoltatore="";
        }
      }
    }
  }
}
