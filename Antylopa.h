#pragma once
#include "Zwierze.h"
class Antylopa :
	public Zwierze
{
public:
	Antylopa(int Y, int X);

	void Rysowanie();

	void Akcja();

	void Kolizja(Organizm* atakujacy);
};

