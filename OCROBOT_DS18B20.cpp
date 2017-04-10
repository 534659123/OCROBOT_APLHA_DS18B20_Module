#include "OCROBOT_DS18B20.h"


DS18B20::DS18B20(byte Addr)
{
	_Addr = Addr;
}

void DS18B20::begin()
{
	 Wire.begin();
}
/*读取温度数据*/
float DS18B20::readTemperature()
{
	Wire.beginTransmission(_Addr); 
	Wire.write(TemperatureRead); 
	Wire.endTransmission();
	
	byte Byte[4];
	Wire.requestFrom((int)_Addr, (int)4);
	while(Wire.available())      //read 4 byte
	{
		Byte[0] = Wire.read();
		Byte[1] = Wire.read();
		Byte[2] = Wire.read();
		Byte[3] = Wire.read();
	}
	float outTransmission;
	ByteToFloat(outTransmission,Byte);
	return outTransmission;
}


/*读取ID*/

void DS18B20::readID(uint8_t *_ID)
{
	Wire.beginTransmission(_Addr); 
	Wire.write(IDRead); 
	Wire.endTransmission();
	
	Wire.requestFrom((int)_Addr, (int)8);
	while(Wire.available())      //read 8 byte
	{
		for(byte a=0;a<8;a++)
		{
			*(_ID + a) = Wire.read();
		}
	}
	
	
}