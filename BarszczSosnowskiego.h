#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :
	public Roslina
{
public:
	BarszczSosnowskiego(int Y, int X);

	void Akcja() override;

	void Kolizja(Organizm* org) override;
};

