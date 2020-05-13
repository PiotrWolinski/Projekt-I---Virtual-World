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

	SetLastX(X);
	SetLastY(Y);
	
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
	else { // rozmnazanie
		SetX(GetLastX());		// organizm, ktory wszedl na pole z takim samym organizmem wroci na swoje poprzednie pole,
		SetY(GetLastY());		// a na polu obok tych dwoch organizmow powstanie nowy
	}
}

std::string Zwierze::GetNazwaKlasy(std::string nazwa) {
	std::istringstream ss(nazwa);
	std::string slowo;
	ss >> slowo;
	ss >> slowo;
	return slowo;
}

