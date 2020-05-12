#pragma once
#include <vector>
#include "Organizm.h"
#include "Wspolrzedne.h"

class Swiat
{
	// rozmiar pola
	int rozmiarX, rozmiarY;
	int tura;

	// pole symulacji - dwu wymiarowa tablica wskaznikow
	Organizm*** pole;
	std::vector<Organizm*> doZabicia;

	std::vector<Organizm*> zwierzeta;

	std::vector<Organizm*> rosliny;

	void WykonajTure();

	void Rysuj();

	void SortujZwierzeta();

	void SortujRosliny();

	void SortujOrganizmy();

	void OdswiezPole();

	void DodajZwierzeta();

	void DodajRosliny();
	
	void UsunMartwe();

public:
	Swiat(const int rozmiarX, const int rozmiarY);

	void SetRozmiarY(const int y);

	void SetRozmiarX(const int x);

	int GetRozmiarY() const;

	int GetRozmiarX() const;

	void Input();
};

