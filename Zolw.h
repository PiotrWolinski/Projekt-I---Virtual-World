#pragma once
#include "Zwierze.h"
class Zolw :
	public Zwierze
{
public:
	Zolw(int Y, int X);

	void Kolizja(Organizm* atakujacy) override;

	void Akcja() override;
};

