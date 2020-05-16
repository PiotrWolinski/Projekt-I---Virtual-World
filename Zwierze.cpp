#include "Zwierze.h"
#include "Swiat.h"

#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include <string>
#include <iostream>

void Zwierze::Akcja() {
	bool moved = false;
	this->wiek++;

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

	/*std::cout << GetNazwaKlasy(typeid(*this).name()) << " poruszyl sie na pole: (" << this->GetX() << ", " << this->GetY() << ")\n";*/

	if (!this->swiat->SprawdzCzyWolne(this->Y, this->X)) {
		this->swiat->GetOrganizmNaPolu(this->Y, this->X)->Kolizja(this);
	}
}

void Zwierze::Kolizja(Organizm* atakujacy) {

	std::string na_polu = GetNazwaKlasy(typeid(*this).name());

	std::string wchodzacy = GetNazwaKlasy(typeid(*atakujacy).name()); 

	std::string komentarz = "";

	if (na_polu != wchodzacy) {
		if (this->GetSila() <= atakujacy->GetSila()) {
			this->zywy = false;
			komentarz = wchodzacy + " zaatakowal i zabil " + na_polu + ' ' + std::to_string(this->GetX()) 
				+ ' ' + std::to_string(this->GetY());

			//std::cout << wchodzacy << " zaatakowal i zabil " << na_polu << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
		}
		else if (this->GetSila() > atakujacy->GetSila()) {
			atakujacy->SetStatus(false);
			komentarz = wchodzacy + " zaatakowal i zostal zabity przez " + na_polu + " na polu " + std::to_string(this->GetX())
				+ ' ' + std::to_string(this->GetY());
			
			//std::cout << wchodzacy << " zaatakowal i zostal zabity przez " << na_polu << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
		}

		this->swiat->DodajKomentarz(komentarz);
	}
	else if (na_polu == wchodzacy && this != atakujacy) { // rozmnazanie

		this->RozmnozSie(atakujacy);

		atakujacy->SetX(atakujacy->GetLastX());		// organizm, ktory wszedl na pole z takim samym organizmem wroci na swoje poprzednie pole,
		atakujacy->SetY(atakujacy->GetLastY());		// a na polu obok tych dwoch organizmow powstanie nowy
	}
}

void Zwierze::RozmnozSie(Organizm* wchodzacy) {

	std::string komentarz = "";

	if (this->rozmnozylSie == false && wchodzacy->GetRozmnozylSie() == false && this->GetWiek() > 5 && wchodzacy->GetWiek() > 5) {

		bool rozmnozony = false;

		int newX = this->X;
		int newY = this->Y;

		if (this->Y > 0 && this->swiat->SprawdzCzyWolne(this->Y - 1, this->X)) {										// sprawdzam gore
			newY--;
			rozmnozony = true;
		}
		else if (this->X < this->swiat->GetRozmiarX() - 1 && this->swiat->SprawdzCzyWolne(this->Y, this->X + 1)) {		// sprawdzam prawo
			newX++;
			rozmnozony = true;
		}
		else if (this->Y < this->swiat->GetRozmiarY() - 1 && this->swiat->SprawdzCzyWolne(this->Y + 1, this->X)) {		// sprawdzam dol
			newY++;
			rozmnozony = true;
		}
		else if (this->X > 0 && this->swiat->SprawdzCzyWolne(this->Y, this->X - 1)) {									// sprawdzam lewo
			newX--;
			rozmnozony = true;
		}

		if (rozmnozony) {
			this->swiat->DodajZwierze(this->GetNazwaKlasy(typeid(*this).name()), newY, newX);
			//std::cout << this->GetNazwaKlasy(typeid(*this).name());
			komentarz = GetNazwaKlasy(typeid(*wchodzacy).name()) + " ma potomka na polu "
				+ std::to_string(newX) + ' ' + std::to_string(newY);

			//std::cout << GetNazwaKlasy(typeid(*wchodzacy).name()) << " ma potomka na polu " << newX << ' ' << newY << '\n';
		}
		else {

			komentarz = GetNazwaKlasy(typeid(*wchodzacy).name()) + " nie moze sie rozmnozyc na polu "
				+ std::to_string(newX) + ' ' + std::to_string(newY);

			//std::cout << this->GetNazwaKlasy(typeid(*this).name()) << " nie moze sie rozmnozyc na polu " << this->GetX() << " " << this->GetY() << '\n';
		}

		this->SetRozmnozylSie(true);
		wchodzacy->SetRozmnozylSie(true);
	} 
	else {

		komentarz = GetNazwaKlasy(typeid(*wchodzacy).name()) + " nie moze sie rozmnozyc na polu "
			+ std::to_string(this->GetX()) + ' ' + std::to_string(this->GetY());

		//std::cout << this->GetNazwaKlasy(typeid(*this).name()) << " nie moze sie rozmnozyc na polu " << this->GetX() << " " << this->GetY() << '\n';
	}

	this->swiat->DodajKomentarz(komentarz);
}
