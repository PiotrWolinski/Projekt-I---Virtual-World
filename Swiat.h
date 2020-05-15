#pragma once
#include "Organizm.h"
#include "Wspolrzedne.h"


#include <string>
#include <vector>

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

	std::vector<Organizm*> poczekalnia;

	void WykonajTure();

	void Rysuj();

	void SortujZwierzeta();

	void SortujRosliny();

	void SortujOrganizmy();

	void OdswiezPole();

	void DodajZwierzeta();

	void DodajRosliny();
	
	void DodajRosline();

	void DodajOrganizmy();
	
	void UsunMartwe();

	void KolejnaTura();

public:
	Swiat(const int rozmiarX, const int rozmiarY);

	void SetRozmiarY(int const y);

	void SetRozmiarX(int const x);

	int GetRozmiarY() const;

	int GetRozmiarX() const;

	void Input();

	int GetTura() const;

	int SprawdzSilePola(int const Y, int const X) const;

	bool SprawdzCzyWolne(int const Y, int const X) const;

	void DodajZwierze(std::string klasa, int const newY, int const newX);

	Organizm* GetOrganizmNaPolu(int const Y, int const X);

};

