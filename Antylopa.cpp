#include "Antylopa.h"
#include "Swiat.h"

#include <iostream>
#include <iomanip>

Antylopa::Antylopa(int Y, int X) {
	this->Y = Y;
	this->X = X;
	this->sila = 4;
	this->inicjatywa = 4;
	this->wiek = 1;
	this->zywy = true;
	this->rozmnozylSie = false;

	SetLastX(this->X);
	SetLastY(this->Y);
}

void Antylopa::Rysowanie() {
	std::cout << std::setw(2) << 'A' << ' ';
}

void Antylopa::Akcja() {
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

	SetLastX(this->X);
	SetLastY(this->Y);
	moved = false;

	while (!moved) {
		int dir = rand() % 4;
		if (dir == 0 && this->Y > 0 && this->lastY != this->Y - 1) {										// w gore
			this->Y--;
			moved = true;
		}
		else if (dir == 1 && this->X < this->swiat->GetRozmiarX() - 1 && this->lastX != this->X + 1) {		// w prawo
			this->X++;
			moved = true;
		}
		else if (dir == 2 && this->Y < this->swiat->GetRozmiarY() - 1 && this->lastY != this->Y + 1) {		// w dol
			this->Y++;
			moved = true;
		}
		else if (dir == 3 && this->X > 0 && this->lastX != this->X - 1) {									// w lewo
			this->X--;
			moved = true;
		}
	}
	/*std::cout << GetNazwaKlasy(typeid(*this).name()) << " poruszyl sie na pole: (" << this->GetX() << ", " << this->GetY() << ")\n";*/

	if (!this->swiat->SprawdzCzyWolne(this->Y, this->X)) {
		this->swiat->GetOrganizmNaPolu(this->Y, this->X)->Kolizja(this);
	}
}

void Antylopa::Kolizja(Organizm* atakujacy) {
	std::string na_polu = GetNazwaKlasy(typeid(*this).name());

	std::string wchodzacy = GetNazwaKlasy(typeid(*atakujacy).name());

	std::string komentarz = "";

	int uciekaj = rand() % 2;

	if (na_polu == wchodzacy && this != atakujacy) {	 // rozmnazanie

		RozmnozSie(atakujacy);

		atakujacy->SetX(atakujacy->GetLastX());		// organizm, ktory wszedl na pole z takim samym organizmem wroci na swoje poprzednie pole,
		atakujacy->SetY(atakujacy->GetLastY());		// a na polu obok tych dwoch organizmow powstanie nowy
	}
	else if (!uciekaj && this != atakujacy) {
		if (na_polu != wchodzacy) {
			if (this->GetSila() <= atakujacy->GetSila()) {
				this->zywy = false;

				komentarz = wchodzacy + " zaatakowal i zabil " + na_polu + " na_polu "
					+ std::to_string(this->GetX()) + ' ' + std::to_string(this->GetY());

				//std::cout << wchodzacy << " zaatakowal i zabil " << na_polu << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
			}
			else if (this->GetSila() > atakujacy->GetSila()) {
				atakujacy->SetStatus(false);

				komentarz = wchodzacy + " zaatakowal i zostal zabity przez " + na_polu + " na_polu "
					+ std::to_string(this->GetX()) + ' ' + std::to_string(this->GetY());

				//std::cout << wchodzacy << " zaatakowal i zostal zabity przez " << na_polu << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
			}
		}
	}
	else if (uciekaj && this != atakujacy) {						// czas na ucieczke
		bool moved = false;

		SetLastX(this->X);
		SetLastY(this->Y);

		int moves = 0;

		while (!moved && moves != 4) {
			int dir = rand() % 4;
			if (dir == 0 && this->Y > 0) {											// w gore
				if (this->swiat->SprawdzCzyWolne(this->Y - 1, this->X)) {
					this->Y--;
					moved = true;
				}
				else {
					moves++;
				}
			}
			else if (dir == 1 && this->X < this->swiat->GetRozmiarX() - 1) {		// w prawo
				if (this->swiat->SprawdzCzyWolne(this->Y, this->X + 1)) {
					this->X++;
					moved = true;
				}
				else {
					moves++;
				}
			}
			else if (dir == 2 && this->Y < this->swiat->GetRozmiarY() - 1) {		// w dol
				if (this->swiat->SprawdzCzyWolne(this->Y + 1, this->X)) {
					this->Y++;
					moved = true;
				}
				else {
					moves++;
				}
			}
			else if (dir == 3 && this->X > 0) {										// w lewo
				if (this->swiat->SprawdzCzyWolne(this->Y, this->X - 1)) {
					this->X--;
					moved = true;
				}
				else {
					moves++;
				}
			}
		}

		if (moved == false) {

			if (this->GetSila() <= atakujacy->GetSila()) {
				this->zywy = false;

				komentarz = wchodzacy + " zaatakowal i zabil " + na_polu + " na_polu "
					+ std::to_string(this->GetX()) + ' ' + std::to_string(this->GetY());

				//std::cout << wchodzacy << " zaatakowal i zabil " << na_polu << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
			}
			else if (this->GetSila() > atakujacy->GetSila()) {
				atakujacy->SetStatus(false);

				komentarz = wchodzacy + " zaatakowal i zostal zabity przez " + na_polu + " na_polu "
					+ std::to_string(this->GetX()) + ' ' + std::to_string(this->GetY());

				//std::cout << wchodzacy << " zaatakowal i zostal zabity przez " << na_polu << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
			}
		}
		else {
			komentarz = wchodzacy + "  nie dogonil " + na_polu + " na_polu "
				+ std::to_string(atakujacy->GetX()) + ' ' + std::to_string(atakujacy->GetY());

			//std::cout << wchodzacy << " nie dogonil " << na_polu << " na polu " << atakujacy->GetX() << ' ' << atakujacy->GetY() << '\n';
		}
	}

	this->swiat->DodajKomentarz(komentarz);
}