#pragma once
#include <vector>
#include "Organizm.h"
#include "Wspolrzedne.h"


class Swiat
{
	// rozmiar pola
	int rozmiarX, rozmiarY;

	// pole symulacji - dwu wymiarowa tablica wskaznikow
	Organizm*** pole;
	std::vector<Organizm*> DoZabicia;


	void StworzPole(int rozmiarX, int rozmiarY);

	void WykonajTure();


	
public:
	Swiat(const int rozmiarX, const int rozmiarY);

	void Rysuj();

	void SetRozmiarY(const int y);

	void SetRozmiarX(const int x);

	int GetRozmiarY() const;

	int GetRozmiarX() const;

};

