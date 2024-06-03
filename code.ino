
#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

const int DHTPIN = 4 ;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);
int e=0;
int c=0;
int d=0;
int x=0;
int y=0;
int enA=9;
int in1=8;
int in2=7;
int cbm = A1;
byte degree[8] = {
  0B01110,
  0B01010,
  0B01110,
  0B00000,
  0B00000,
  0B00000,
  0B00000,
  0B00000
};

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT); 
  pinMode(cbm, INPUT);
  lcd.init();                      
  lcd.backlight();
  dht.begin();
  lcd.setCursor(3,0);
  lcd.print("DO AN: SAO");
  lcd.setCursor(1,1);
  lcd.print("PHOI DO TU DONG");
  lcd.createChar(1, degree);
  delay(5000);
  lcd.clear();
}
void chayra(){
   analogWrite(enA,140);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
}
void chayvao(){
 analogWrite(enA,160);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
}
void dung(){
  analogWrite(enA,0);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
}
void loop() {
  int xung = digitalRead(A2); 
  int sang = map(xung,0,1,0,1000);
  int mua= digitalRead(cbm);
  int h = dht. readHumidity();
  int t = dht.readTemperature();
  if (mua==1){
    x=0;
    y++;
    c=0;
    d=0;
    e=0;
    if(y< 2){
    lcd.setCursor(4,0);
    lcd.print("DANG MUA");
    lcd.setCursor(3,1);
    lcd.print("KEO DO VAO");
    chayvao();
    delay(1000);
    lcd.clear();
    }
    
    else{
 lcd.setCursor(1,0);
 lcd.print("NHIET DO:");
 lcd.setCursor(10,0);
 lcd.print(t);
 lcd.write(1);
 lcd.print("C");
 lcd.setCursor(1,1);
 lcd.print("DO AM:");
 lcd.setCursor(10,1);
 lcd.print(h);
 lcd.setCursor(12,1);
 lcd.print("%");
    dung();
    delay(1000);
    lcd.clear();
    }
    
    }
if(mua==0){
 if(t>40){
 x=0;
 y=0;
 c++;
 d=0;
 e=0;
 if(c< 2){
    lcd.setCursor(0,0);
    lcd.print("NHIET DO QUA CAO");
    lcd.setCursor(3,1);
    lcd.print("KEO DO VAO");
    chayvao();
    delay(1000);
    lcd.clear();
    }
    
    else{
 lcd.setCursor(1,0);
 lcd.print("NHIET DO:");
 lcd.setCursor(10,0);
 lcd.print(t);
 lcd.write(1);
 lcd.print("C");
 lcd.setCursor(1,1);
 lcd.print("DO AM:");
 lcd.setCursor(10,1);
 lcd.print(h);
 lcd.setCursor(12,1);
 lcd.print("%");
    dung();
    delay(1000);
    lcd.clear();
    }
    }
        if(h>75){
      if(sang > 500 ){
        x=0;
        y=0;
        c=0;
        d++;
        e=0;
        
         if(d<2){
       lcd.setCursor(1,0);
    lcd.print("SANG CO SUONG");
    lcd.setCursor(3,1);
    lcd.print("KEO DO RA");
    chayra();
    delay(1000);
    lcd.clear();
    }
    
    else{
 lcd.setCursor(1,0);
 lcd.print("NHIET DO:");
 lcd.setCursor(10,0);
 lcd.print(t);
 lcd.write(1);
 lcd.print("C");
 lcd.setCursor(1,1);
 lcd.print("DO AM:");
 lcd.setCursor(10,1);
 lcd.print(h);
 lcd.setCursor(12,1);
 lcd.print("%");
    dung();
    delay(1000);
    lcd.clear();
      }
      }
      else{
        x=0;
        y=0;
        c=0;
        d=0;
        e++;
         if(e<2){
       lcd.setCursor(2,0);
    lcd.print("DO AM QUA CAO");
    lcd.setCursor(3,1);
    lcd.print("KEO DO VAO");
    chayvao();
    delay(1000);
    lcd.clear();
    }
    else{
 lcd.setCursor(1,0);
 lcd.print("NHIET DO:");
 lcd.setCursor(10,0);
 lcd.print(t);
 lcd.write(1);
 lcd.print("C");
 lcd.setCursor(1,1);
 lcd.print("DO AM:");
 lcd.setCursor(10,1);
 lcd.print(h);
 lcd.setCursor(12,1);
 lcd.print("%");
    dung();
    delay(1000);
    lcd.clear();
      }
    }
        }
  if(((t<40)&&(t>20)) &&((h>30)&&(h<75))){
     y=0;
    x++;
    c=0;
    d=0;
    e=0;
    if(x<2){
       lcd.setCursor(6,0);
    lcd.print("NANG");
    lcd.setCursor(3,1);
    lcd.print("KEO DO RA");
    chayra();
    delay(1000);
    lcd.clear();
    }
    
    else{
      
 lcd.setCursor(1,0);
 lcd.print("NHIET DO:");
 lcd.setCursor(10,0);
 lcd.print(t);
 lcd.write(1);
 lcd.print("C");
 lcd.setCursor(1,1);
 lcd.print("DO AM:");
 lcd.setCursor(10,1);
 lcd.print(h);
 lcd.setCursor(12,1);
 lcd.print("%");
    dung();
    delay(1000);
    lcd.clear();
    }
    
    }
    
  }
  

} 
 


  
