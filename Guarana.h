#pragma once
#include "Roslina.h"
class Guarana :
	public Roslina
{
public:
	Guarana(int Y, int X);

	void Kolizja(Organizm* org) override;
};
