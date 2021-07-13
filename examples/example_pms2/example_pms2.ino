#include <PMserial.h>
SerialPM pms(PMSx003, 10, 11);  // PMSx003, RX, TX

const int led = 13;

void setup() {
  Serial.begin(9600);
  Serial.println("Micro Projects th");
  pms.init();                   // config serial port

 pinMode(led, OUTPUT);
  
}

void loop() {
  pms.read();                   // read the PM sensor
  Serial.print(F("PM1.0 ")); Serial.print(pms.pm01); Serial.print(F(", "));
  Serial.print(F("PM2.5 ")); Serial.print(pms.pm25); Serial.print(F(", "));
  Serial.print(F("PM10 ")) ; Serial.print(pms.pm10); Serial.println(F(" [ug/m3]"));


  if(pms.pm10 >= 2000){
     digitalWrite(led, HIGH); 
  }
  else if(pms.pm10 < 2000){
     digitalWrite(led, LOW); 
  }

  
  delay(1000);                 // wait for 10 seconds
}
