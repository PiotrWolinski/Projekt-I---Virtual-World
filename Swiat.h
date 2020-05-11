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
	std::vector<Organizm*> doZabicia;

	std::vector<Organizm*> zwierzeta;

	std::vector<Organizm*> rosliny;

	void StworzPole(int rozmiarX, int rozmiarY);

	void WykonajTure();

	void Rysuj();
	
public:
	Swiat(const int rozmiarX, const int rozmiarY);

	void DodajZwierzeta();

	void DodajRosliny();

	void SetRozmiarY(const int y);

	void SetRozmiarX(const int x);

	int GetRozmiarY() const;

	int GetRozmiarX() const;

	void Input();

};

