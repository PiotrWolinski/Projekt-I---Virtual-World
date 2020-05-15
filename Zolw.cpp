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
	}
	/*std::cout << GetNazwaKlasy(typeid(*this).name()) << " poruszyl sie na pole: (" << this->GetX() << ", " << this->GetY() << ")\n";*/
}

// kolizja jest wywolywana dla organizmu, ktory byl pierwszy na danym polu
void Zolw::Kolizja(Organizm* other) {
	std::string na_polu = GetNazwaKlasy(typeid(*this).name());

	std::string wchodzacy = GetNazwaKlasy(typeid(*other).name());

	if (na_polu != wchodzacy) {

		if (other->GetSila() < this->GetSila()) {
			other->SetStatus(false);
			std::cout << na_polu << " zabil " << wchodzacy << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
		}
		else if (other->GetSila() < 5) {
			other->SetX(other->GetLastX());
			other->SetY(other->GetLastY());
			std::cout << na_polu << " odbil atak " << wchodzacy << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
		}
		else if (other->GetSila() >= 5) {
			this->zywy = false;
			std::cout << na_polu << " zostal zabity przez " << wchodzacy << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
		}
	}
	else if (this != other && na_polu == wchodzacy) { // rozmnazanie
		other->SetX(other->GetLastX());		// organizm, ktory wszedl na pole z takim samym organizmem wroci na swoje poprzednie pole,
		other->SetY(other->GetLastY());		// a na polu obok tych dwoch organizmow powstanie nowy
		RozmnozSie();
		std::cout << na_polu << " rozmnaza sie z " << wchodzacy << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
	}
}