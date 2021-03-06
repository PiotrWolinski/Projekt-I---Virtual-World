#include "Roslina.h"
#include "Organizmy.h"
#include "Swiat.h"

#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include <string>
#include <iostream>
#include <iomanip>

void Roslina::Akcja() {
	int rozmnoz_sie = rand() % 100;

	if (rozmnoz_sie < SPAWN_RATE_R) {

		std::string komentarz = "";

		int newX = this->X;
		int newY = this->Y;

		int dir = rand() % 4;
		bool zasiane = false;
		int tmp = dir;

		do {
			if (dir == 0) {
				if (this->Y > 0 && this->swiat->SprawdzCzyWolne(this->Y - 1, this->X)) {									// sprawdzam gore
					newY--;
					zasiane = true;
				}
				else {
					dir = (++dir) % 4;
				}
			}
			else if (dir == 1) {
				if (this->X < this->swiat->GetRozmiarX() - 1 && this->swiat->SprawdzCzyWolne(this->Y, this->X + 1)) {		// sprawdzam prawo
					newX++;
					zasiane = true;
				}
				else {
					dir = (++dir) % 4;
				}
			}
			else if (dir == 2) {

				if (this->Y < this->swiat->GetRozmiarY() - 1 && this->swiat->SprawdzCzyWolne(this->Y + 1, this->X)) {		// sprawdzam dol
					newY++;
					zasiane = true;
				}
				else {
					dir = (++dir) % 4;
				}
			}
			else if (dir == 3) {
				if (this->X > 0 && this->swiat->SprawdzCzyWolne(this->Y, this->X - 1)) {									// sprawdzam lewo
					newX--;
					zasiane = true;
				}
				else {
					dir = (++dir) % 4;
				}
			}
		} while (!zasiane && dir != tmp);

		if (zasiane && this->rozmnozylSie == false) {

			komentarz = GetNazwaKlasy(typeid(*this).name()) + " zasial dziecko na polu "
				+ std::to_string(newX) + ' ' + std::to_string(newY);

			this->swiat->DodajRosline(this->GetNazwaKlasy(typeid(*this).name()), newY, newX);
		}

		this->swiat->DodajKomentarz(komentarz);
	}
}

void Roslina::Rysowanie() {
	std::cout << std::setw(2) << this->symbol << ' ';
}

void Roslina::Kolizja(Organizm* atakujacy) {

	std::string komentarz = "";

	std::string na_polu = GetNazwaKlasy(typeid(*this).name());

	std::string wchodzacy = GetNazwaKlasy(typeid(*atakujacy).name());

	if (atakujacy->GetSila() >= this->GetSila()) {
		this->stan = MARTWY;

		komentarz = wchodzacy + " zjadl " + na_polu + " na polu " 
			+ std::to_string(this->GetX()) + ' ' + std::to_string(this->GetY());
	}
	else if (atakujacy->GetSila() < this->GetSila()) {
		atakujacy->SetStan(MARTWY);

		komentarz = wchodzacy + " zostal zabity przez " + na_polu + " na polu "
			+ std::to_string(this->GetX()) + ' ' + std::to_string(this->GetY());
	}

	this->swiat->DodajKomentarz(komentarz);
}