#include "Zolw.h"
#include "Swiat.h"

#include <iostream>
#include <iomanip>

Zolw::Zolw(int Y, int X) {
	this->Y = Y;
	this->X = X;
	this->sila = 2;
	this->inicjatywa = 1;
	this->wiek = 1;
	this->zywy = true;
	this->rozmnozylSie = false;

	SetLastX(this->X);
	SetLastY(this->Y);
}

void Zolw::Rysowanie() {
	std::cout << std::setw(2) << 'Z' << ' ';
}

void Zolw::Akcja() {
	bool moved = false;
	this->wiek++;

	int shouldIMove = rand() % 4;
	if (shouldIMove == 0) {

		SetLastX(this->X);
		SetLastY(this->Y);

		while (!moved) {
			int dir = rand() % 4;
			if (dir == 0 && this->Y > 0) {											// w gore
				this->Y--;
				moved = true;
			}
			else if (dir == 1 && this->X < this->swiat->GetRozmiarX() - 1) {		// w prawo
				this->X++;
				moved = true;
			}
			else if (dir == 2 && this->Y < this->swiat->GetRozmiarY() - 1) {		// w dol
				this->Y++;
				moved = true;
			}
			else if (dir == 3 && this->X > 0) {										// w lewo
				this->X--;
				moved = true;
			}
		}

		if (!this->swiat->SprawdzCzyWolne(this->Y, this->X)) {
			this->swiat->GetOrganizmNaPolu(this->Y, this->X)->Kolizja(this);
		}
	}

	/*std::cout << GetNazwaKlasy(typeid(*this).name()) << " poruszyl sie na pole: (" << this->GetX() << ", " << this->GetY() << ")\n";*/
}

void Zolw::Kolizja(Organizm* atakujacy) {
	Organizm* org = this->swiat->GetOrganizmNaPolu(this->Y, this->X);

	std::string na_polu = GetNazwaKlasy(typeid(*this).name());

	std::string wchodzacy = GetNazwaKlasy(typeid(*atakujacy).name());

	if (na_polu != wchodzacy) {

		if (atakujacy->GetSila() < this->GetSila()) {
			atakujacy->SetStatus(false);
			std::cout << wchodzacy << " zaatakowal i zostal zabity przez " << na_polu << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
		}
		else if (atakujacy->GetSila() < 5) {
			atakujacy->SetX(atakujacy->GetLastX());
			atakujacy->SetY(atakujacy->GetLastY());
			std::cout << wchodzacy << " zostal odgoniony przez " << na_polu << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
		}
		else if (atakujacy->GetSila() >= 5) {
			this->zywy = false;
			std::cout << wchodzacy << " zaatakowal i zabil " << na_polu << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
		}
	}
	else if (na_polu == wchodzacy && this != atakujacy) { // rozmnazanie

		RozmnozSie(atakujacy);

		atakujacy->SetX(atakujacy->GetLastX());		// organizm, ktory wszedl na pole z takim samym organizmem wroci na swoje poprzednie pole,
		atakujacy->SetY(atakujacy->GetLastY());		// a na polu obok tych dwoch organizmow powstanie nowy
	}
}