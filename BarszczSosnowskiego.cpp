#include "BarszczSosnowskiego.h"
#include <iomanip>
#include <iostream>

BarszczSosnowskiego::BarszczSosnowskiego(int Y, int X) {
	this->Y = Y;
	this->X = X;
	this->sila = 10;
	this->inicjatywa = 0;
	this->wiek = 1;
	this->zywy = true;
	this->rozmnozylSie = false;
}

void BarszczSosnowskiego::Rysowanie() {
	std::cout << std::setw(2) << 'B' << ' ';
}

void BarszczSosnowskiego::Kolizja(Organizm* org) {

}