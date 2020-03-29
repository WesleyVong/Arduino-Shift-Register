/*
PISO v1.0
Tested for 74HC165
Wesley Vong
*/

#include "Arduino.h"

class PISO
{
private:
	byte inPin;
	byte latPin;
	byte clkPin;
	uint16_t size;
	byte inputArray[256];
	byte checkArray[256];

public:
	PISO(byte inPin, byte latPin, byte clkPin, byte size);

	void read();
	int getValueAt(byte location);
	int ValueChanged(byte location);
};