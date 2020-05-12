#include "Owca.h"
#include <iostream>
#include <iomanip>

Owca::Owca(int Y, int X) {
	this->Y = Y;
	this->X = X;
	this->sila = 4;
	this->inicjatywa = 4;
	this->wiek = 1;
	this->zywy = true;
}

void Owca::Rysowanie() {
	std::cout << std::setw(2) << 'O' << ' ';
}