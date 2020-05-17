#include "Wilk.h"
#include <iostream>
#include <iomanip>

void Wilk::Rysowanie() {
	std::cout << std::setw(2) << this->symbol << ' ';
}

Wilk::Wilk(int Y, int X) {
	this->symbol = 'W';
	this->Y = Y;
	this->X = X;
	this->sila = 9;
	this->inicjatywa = 5;
	this->wiek = 1;
	this->zywy = true;
	this->rozmnozylSie = false;

	SetLastX(this->X);
	SetLastY(this->Y);
}