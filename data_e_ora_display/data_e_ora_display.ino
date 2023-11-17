#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  



//imposta ora
//secondi, no sopra i 60 
int s=0;

//minuti, no sopra i 60 
int m=43;

//ore, no sopra le 24
int o=21;

//imposta data
//giorno, no supera i 30
int g=2;

//mese, no supera i 12
int M=4;

//anno, infinito
int a=2019;
  
void setup() {  
   //impostiamo il numero di colonne ed il numero di righe di lcd  
  lcd.begin(16, 2);  
  // Visualizzo il messaggio sul display  
  lcd.print("Prog Data e ora");  
  delay (2000);
  lcd.clear();

    
  //data
  lcd.setCursor(0, 0);  
  lcd.print("Data");  
   lcd.setCursor(6, 0);  
  lcd.print("__/__/____"); 

  //ora
    lcd.setCursor(0, 1);  
  lcd.print("Ora");  
   lcd.setCursor(8, 1);  
  lcd.print("__:__:__");
   

   lcd.setCursor(14, 1);  
  lcd.print(s);  
   lcd.setCursor(11, 1);  
  lcd.print(m); 
      lcd.setCursor(8, 1);  
  lcd.print(o);  
     lcd.setCursor(6, 0);  
  lcd.print(g);   
    lcd.setCursor(9, 0);  
  lcd.print(M); 
   lcd.setCursor(12, 0);  
  lcd.print(a);  
}  
  
void loop() {  
  
    for (int i=0; i<=60; i++) {
    s++;
    delay (1000);
  lcd.setCursor(14, 1);  
  lcd.print(s);  
  
   if (s>=60) {
   m++;
   lcd.setCursor(11, 1);  
  lcd.print(m);  
    s=0; 
       lcd.setCursor(14, 1);  
  lcd.print("__");  
   }

  if (m>=60) {
    o++;
    lcd.setCursor(8, 1);  
  lcd.print(o);  
    m=0;
        lcd.setCursor(11, 1);  
  lcd.print("__");  
  }

  if (o>=24) {
    o=0;
     lcd.setCursor(8, 1);  
  lcd.print("__");  
  g++;
      lcd.setCursor(6, 0);  
  lcd.print(g);  
  }

  if(g>=30) {
    M++;
        lcd.setCursor(9, 0);  
  lcd.print(M);  
    g=0;
        lcd.setCursor(6, 0);  
  lcd.print(g);  
  }

  if(M>=12) {
   a++;
       lcd.setCursor(12, 0);  
  lcd.print(a);  
   M=0;
       lcd.setCursor(13, 0);  
  lcd.print(M);  
    
  }
   
  }
}  
