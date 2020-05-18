#include "Trawa.h"
#include <iomanip>
#include <iostream>

Trawa::Trawa(int Y, int X) {
	this->symbol = 'T';
	this->Y = Y;
	this->X = X;
	this->sila = 0;
	this->inicjatywa = 0;
	this->wiek = 1;
	this->stan = true;
	this->rozmnozylSie = false;
}