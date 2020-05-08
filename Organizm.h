#pragma once
#include "Wspolrzedne.h"
class Swiat;

class Organizm
{
	char symbol;
	int sila;
	int inicjatywa;
	int dlugoscZycia;
	Swiat& swiat;
	Wspolrzedne polozenie;
public:

	virtual void Akcja() = 0;

	virtual void Kolizja() = 0;

	virtual void Rysowanie() = 0;

};

