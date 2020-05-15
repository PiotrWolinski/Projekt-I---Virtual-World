#include "WilczeJagody.h"
#include <iomanip>
#include <iostream>

WilczeJagody::WilczeJagody(int Y, int X) {
	this->Y = Y;
	this->X = X;
	this->sila = 99;
	this->inicjatywa = 0;
	this->wiek = 1;
	this->zywy = true;
	this->rozmnozylSie = false;
}

void WilczeJagody::Rysowanie() {
	std::cout << std::setw(2) << 'J' << ' ';
}