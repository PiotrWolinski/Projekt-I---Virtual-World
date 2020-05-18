#pragma once
#include "Organizm.h"
#include "Wspolrzedne.h"

#include <string>
#include <vector>

class Swiat
{
	int rozmiarX, rozmiarY;

	int tura;

	Organizm*** pole;

	std::vector<Organizm*> zwierzeta;

	std::vector<Organizm*> rosliny;

	std::vector<std::string> komentarze;

	Organizm* czlowiek;

	void WykonajTure();

	void Rysuj();

	void SortujZwierzeta();

	void SortujRosliny();

	void DodajOrganizmy();
	
	void UsunMartwe();

	void KolejnaTura();

	void Skomentuj();

	void Zapisz();

	void Wczytaj();

	void WyczyscDane();

	void InitPole();

public:
	Swiat(int const rozmiarX, int const rozmiarY);

	void SetRozmiarY(int const y);

	void SetRozmiarX(int const x);

	int GetRozmiarY() const;

	int GetRozmiarX() const;

	void Input();

	int GetTura() const;

	int SprawdzSilePola(int const Y, int const X) const;

	bool SprawdzCzyWolne(int const Y, int const X) const;

	void DodajZwierze(std::string klasa, int const newY, int const newX);

	void DodajRosline(std::string klasa, int const newY, int const newX);

	void OdswiezPole();

	void DodajKomentarz(std::string komentarz);

	Organizm* GetOrganizmNaPolu(int const Y, int const X) const;

	~Swiat();
};

