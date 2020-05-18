#include "Mlecz.h"
#include "Swiat.h"
#include "Organizmy.h"

#include <iomanip>
#include <iostream>

Mlecz::Mlecz(int Y, int X) {
	this->symbol = 'M';
	this->Y = Y;
	this->X = X;
	this->sila = 0;
	this->inicjatywa = 0;
	this->wiek = 1;
	this->stan = true;
	this->rozmnozylSie = false;
}

void Mlecz::Akcja() {
	for (int i = 0; i < 3; ++i) {
		int rozmnoz_sie = rand() % 100;

		std::string komentarz = "";

		if (rozmnoz_sie < SPAWN_RATE_R) {

			int newX = this->X;
			int newY = this->Y;

			int dir = rand() % 4;
			bool zasiane = false;
			int tmp = dir;

			do {
				if (dir == 0) {
					if (this->Y > 0 && this->swiat->SprawdzCzyWolne(this->Y - 1, this->X)) {										// sprawdzam gore
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
			this->swiat->OdswiezPole();
		}
	}
}