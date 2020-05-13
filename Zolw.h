#pragma once
#include "Zwierze.h"
class Zolw :
	public Zwierze
{
public:
	Zolw(int Y, int X);

	void Rysowanie();

	void Kolizja(Organizm* other);

	void Akcja();
};

