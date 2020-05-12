#include "Antylopa.h"
#include <iostream>
#include <iomanip>

Antylopa::Antylopa(int Y, int X) {
	this->Y = Y;
	this->X = X;
	this->sila = 4;
	this->inicjatywa = 4;
	this->wiek = 1;
	this->zywy = true;
}

void Antylopa::Rysowanie() {
	std::cout << std::setw(2) << 'A' << ' ';
}