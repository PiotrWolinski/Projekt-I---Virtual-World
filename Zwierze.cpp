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

void Zwierze::Kolizja(Organizm* other) {
	std::string na_polu = GetNazwaKlasy(typeid(*other).name());

	std::string wchodzacy = GetNazwaKlasy(typeid(*this).name());
	
	if (na_polu != wchodzacy) {
		if (other->GetSila() > this->GetSila()) {
			this->zywy = false;
		}
		else if (other->GetSila() < this->GetSila()) {
			other->SetStatus(false);
		}
	}

}


std::string Zwierze::GetNazwaKlasy(std::string nazwa) {
	std::istringstream ss(nazwa);
	std::string slowo;
	ss >> slowo;
	ss >> slowo;
	return slowo;
}