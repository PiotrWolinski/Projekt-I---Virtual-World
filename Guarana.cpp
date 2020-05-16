#include "Guarana.h"
#include "Swiat.h"

#include <iomanip>
#include <iostream>

Guarana::Guarana(int Y, int X) {
	this->Y = Y;
	this->X = X;
	this->sila = 0;
	this->inicjatywa = 0;
	this->wiek = 1;
	this->zywy = true;
	this->rozmnozylSie = false;
}

void Guarana::Rysowanie() {
	std::cout << std::setw(2) << 'G' << ' ';
}

void Guarana::Kolizja(Organizm* atakujacy) {

	std::string na_polu = GetNazwaKlasy(typeid(*this).name());

	std::string wchodzacy = GetNazwaKlasy(typeid(*atakujacy).name());

	std::string komentarz = "";

	if (atakujacy->GetSila() >= this->GetSila()) {
		this->zywy = false;
		atakujacy->SetSila(atakujacy->GetSila() + 3);

		komentarz = wchodzacy + " zjadl " + na_polu + " na polu " 
			+ std::to_string(this->GetX()) + ' ' + std::to_string(this->GetY());

		//std::cout << wchodzacy << " zjadl " << na_polu << " na polu " 
			//<< this->GetX() << ' ' << this->GetY() << '\n';
	}
	else if (atakujacy->GetSila() < this->GetSila()) {
		atakujacy->SetStatus(false);

		komentarz = wchodzacy + " probowal zjesc i nie dal rady " + na_polu + " na polu " 
			+ std::to_string(this->GetX()) + ' ' + std::to_string(this->GetY());

		//std::cout << wchodzacy << " probowal zjesc i nie dal rady " << na_polu << " na polu " 
			//<< this->GetX() << ' ' << this->GetY() << '\n';
	}

	this->swiat->DodajKomentarz(komentarz);
}