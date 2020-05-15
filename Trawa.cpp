#include "Trawa.h"
#include <iomanip>
#include <iostream>

Trawa::Trawa(int Y, int X) {
	this->Y = Y;
	this->X = X;
	this->sila = 0;
	this->inicjatywa = 0;
	this->wiek = 1;
	this->zywy = true;
	this->rozmnozylSie = false;
}

void Trawa::Rysowanie() {
	std::cout << std::setw(2) << 'T' << ' ';
}