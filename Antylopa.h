#pragma once
#include "Zwierze.h"
class Antylopa :
	public Zwierze
{
public:
	Antylopa(int Y, int X);

	void Akcja() override;

	void Kolizja(Organizm* atakujacy) override;
};

