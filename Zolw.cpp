#include "Zolw.h"

#include <iostream>
#include <iomanip>

Zolw::Zolw(int Y, int X) {
	this->Y = Y;
	this->X = X;
	this->sila = 2;
	this->inicjatywa = 1;
	this->wiek = 1;
	this->zywy = true;
}

void Zolw::Rysowanie() {
	std::cout << std::setw(2) << 'Z' << ' ';
}