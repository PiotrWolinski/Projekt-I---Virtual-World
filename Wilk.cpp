#include "Wilk.h"
#include <iostream>
#include <iomanip>
#include <initializer_list>

void Wilk::Rysowanie() {
	std::cout << std::setw(2) << 'W' << ' ';
}

Wilk::Wilk(int Y, int X) {
	this->Y = Y;
	this->X = X;
	this->sila = 9;
	this->inicjatywa = 5;
	this->dlugoscZycia = 1;
}