#include "OCROBOT_DS18B20.h"
DS18B20 ds(0x01);
void setup() 
{
     ds.begin();
     Serial.begin(9600);
}

void loop() 
{
      float Temperature =  ds.readTemperature();
      Serial.println(Temperature);   //print Temperature
      byte ID[8];
      ds.readID(ID);
      for(byte num = 0;num<8;num++)
      {
        Serial.print(ID[num]);
        Serial.print(",");
        }
      Serial.println();
      delay(1000);
}