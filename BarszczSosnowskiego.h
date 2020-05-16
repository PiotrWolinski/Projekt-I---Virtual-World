#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :
	public Roslina
{
public:
	BarszczSosnowskiego(int Y, int X);

	void Akcja();

	void Rysowanie();

	void Kolizja(Organizm* org);
};

