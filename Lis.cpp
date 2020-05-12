#include "Lis.h"
#include <iostream>
#include <iomanip>

Lis::Lis(int Y, int X) {
	this->Y = Y;
	this->X = X;
	this->sila = 3;
	this->inicjatywa = 7;
	this->dlugoscZycia = 1;
}

void Lis::Rysowanie() {
	std::cout << std::setw(2) << 'L' << ' ';
}