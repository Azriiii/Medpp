#include "DHT.h"
#define DHTPIN A0 
#define DHTTYPE DHT11
DHT  dht(DHTPIN,DHTTYPE); 
 
void setup(){
 
  Serial.begin(9600);
    dht.begin();
 
}//end "setup()"
 
void loop(){
 
  
    
    float t = dht.readTemperature(); 
    Serial.print(t);
    Serial.print(",") ; 
    Serial.flush() ;
    delay(2000);
 
 
}// end loop() 
