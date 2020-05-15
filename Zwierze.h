#pragma once
#include "Organizm.h"
#include <string>
class Zwierze :
	public Organizm
{
public:
	void Akcja();

	void Kolizja(Organizm* org);

	void RozmnozSie(Organizm* org);
};

