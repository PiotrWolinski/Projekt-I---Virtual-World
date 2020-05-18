#include "Wilk.h"
#include <iostream>
#include <iomanip>

Wilk::Wilk(int Y, int X) {
	this->symbol = 'W';
	this->Y = Y;
	this->X = X;
	this->sila = 9;
	this->inicjatywa = 5;
	this->wiek = 1;
	this->stan = true;
	this->rozmnozylSie = false;

	SetLastX(this->X);
	SetLastY(this->Y);
}