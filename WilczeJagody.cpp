#include "WilczeJagody.h"
#include <iomanip>
#include <iostream>

WilczeJagody::WilczeJagody(int Y, int X) {
	this->symbol = 'J';
	this->Y = Y;
	this->X = X;
	this->sila = 99;
	this->inicjatywa = 0;
	this->wiek = 1;
	this->stan = true;
	this->rozmnozylSie = false;
}