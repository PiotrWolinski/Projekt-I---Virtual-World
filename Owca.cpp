#include "Owca.h"
#include <iostream>
#include <iomanip>

Owca::Owca(int Y, int X) {
	this->symbol = 'O';
	this->Y = Y;
	this->X = X;
	this->sila = 4;
	this->inicjatywa = 4;
	this->wiek = 1;
	this->stan = true;
	this->rozmnozylSie = false;

	SetLastX(this->X);
	SetLastY(this->Y);
}