#pragma once
#include "Wspolrzedne.h"
//#include "Swiat.h"

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

	virtual void Akcja() = 0;

	//virtual void Kolizja() = 0;

	virtual void Rysowanie() = 0;

	void SetSwiat(Swiat* swiat);

	Swiat* GetSwiat() const;

	int GetX() const;

	void SetX(const int X);

	int GetY() const;

	void SetY(const int Y);
	//dodam wszystkie getery i setery
};

