#pragma once
#include "Organizm.h"
#include <string>
class Roslina :
	public Organizm
{
public:
	void Akcja();

	void Kolizja(Organizm* org);

	void Rysowanie();
};

