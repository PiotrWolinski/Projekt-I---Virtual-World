#include "Zwierze.h"
#include "Swiat.h"


#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include <string>
#include <sstream>
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
}

// kolizja jest wywolywana dla organizmu, ktory byl pierwszy na danym polu
void Zwierze::Kolizja(Organizm* other) {
	std::string na_polu = GetNazwaKlasy(typeid(*this).name());

	std::string wchodzacy = GetNazwaKlasy(typeid(*other).name());
	
	if (na_polu != wchodzacy) {
		if (this->GetSila() <= other->GetSila()) {
			this->zywy = false;
			std::cout << na_polu << " zostal zabity przez " <<  wchodzacy << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
		}
		else if (this->GetSila() > other->GetSila()) {
			other->SetStatus(false);
			std::cout << na_polu << " zabil " << wchodzacy << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
		}
	}
	else if (na_polu == wchodzacy && this != other) { // rozmnazanie
		other->SetX(other->GetLastX());		// organizm, ktory wszedl na pole z takim samym organizmem wroci na swoje poprzednie pole,
		other->SetY(other->GetLastY());		// a na polu obok tych dwoch organizmow powstanie nowy
		RozmnozSie();
		std::cout << na_polu << " rozmnaza sie z " << wchodzacy << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';
	}
}

std::string Zwierze::GetNazwaKlasy(std::string nazwa) {
	std::istringstream ss(nazwa);
	std::string slowo;
	ss >> slowo;
	ss >> slowo;
	return slowo;
}

void Zwierze::RozmnozSie() {
	if (this->rozmnozylSie == false && this->GetWiek() > 5) {

		bool rozmnozony = false;
		int proby = 0;

		int newX = this->X;
		int newY = this->Y;

		while (!rozmnozony && proby != 4) {
			int dir = rand() % 4;
			if (dir == 0 && this->Y > 0) {											// sprawdzam gore
				if (this->swiat->SprawdzCzyWolne(this->Y - 1, this->X)) {
					newY--;
					rozmnozony = true;
					break;
				}
				else {
					proby++;
				}
			}
			else if (dir == 1 && this->X < this->swiat->GetRozmiarX() - 1) {		// sprawdzam prawo
				if (this->swiat->SprawdzCzyWolne(this->Y, this->X + 1)) {
					newX++;
					rozmnozony = true;
					break;
				}
				else {
					proby++;
				}
			}
			else if (dir == 2 && this->Y < this->swiat->GetRozmiarY() - 1) {		// sprawdzam dol
				if (this->swiat->SprawdzCzyWolne(this->Y + 1, this->X)) {
					newY++;
					rozmnozony = true;
					break;
				}
				else {
					proby++;
				}
			}
			else if (dir == 3 && this->X > 0) {										// sprawdzam lewo
				if (this->swiat->SprawdzCzyWolne(this->Y, this->X - 1)) {
					newX--;
					rozmnozony = true;
					break;
				}
				else {
					proby++;
				}
			}
		}

		this->swiat->DodajDoPoczekalni(this->GetNazwaKlasy(typeid(*this).name()), newY, newX);
		//std::cout << this->GetNazwaKlasy(typeid(*this).name());

		this->SetRozmnozylSie(true);
	}
}
