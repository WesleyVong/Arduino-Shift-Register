/*
PISO v1.0
Tested for 74HC165
Wesley Vong
*/

#include "Arduino.h"
#include "PISO.h"

PISO::PISO(byte _inPin, byte _latPin, byte _clkPin, byte _size)
{
	inPin = _inPin;
	latPin = _latPin;
	clkPin = _clkPin;
	size = _size;

	pinMode(inPin, INPUT_PULLDOWN);
	pinMode(latPin, OUTPUT);
	pinMode(clkPin, OUTPUT);
}

void PISO::read()
{
	digitalWrite(latPin, LOW);
	digitalWrite(latPin, HIGH);
	for (byte i = 0; i < size; i++) {
		checkArray[i] = inputArray[i];
		inputArray[i] = digitalRead(inPin);
		digitalWrite(clkPin, HIGH);
		digitalWrite(clkPin, LOW);
	}
}

int PISO::getValueAt(byte location)
{
	return inputArray[location];
}

int PISO::ValueChanged(byte location)
{
	return (!(inputArray[location] == checkArray[location]));
}
