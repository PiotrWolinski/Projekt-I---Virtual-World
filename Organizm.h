#pragma once
#include "Wspolrzedne.h"
class Swiat;

class Organizm
{
protected:
	int id;
	char symbol;
	int sila;
	int inicjatywa;
	int dlugoscZycia;
	Swiat *swiat;
	int X;
	int Y;
public:

	//virtual void akcja() = 0;

	//virtual void kolizja() = 0;

	virtual void Rysowanie() = 0;

	//dodam wszystkie getery i setery
};

