#pragma once
#include "Organizm.h"
#include <string>
class Zwierze :
	public Organizm
{
public:
	virtual void Akcja();

	virtual void Kolizja(Organizm* org);

	virtual void RozmnozSie(Organizm* org);

	void Rysowanie();
};

