#ifndef _OCROBOT_DS18B20_H_
#define _OCROBOT_DS18B20_H_

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


#include <Wire.h>
#include "Variable.h"


#define TemperatureRead 2
#define IDRead 1

class  DS18B20
{
	public:
		DS18B20(byte Addr);
		void begin();
		float readTemperature();
		void readID(uint8_t *_ID);

	private:
		byte _Addr;
};


#endif