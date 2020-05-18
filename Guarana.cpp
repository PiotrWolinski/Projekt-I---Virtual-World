#include "Guarana.h"
#include "Swiat.h"

#include <iomanip>
#include <iostream>

Guarana::Guarana(int Y, int X) {
	this->symbol = 'G';
	this->Y = Y;
	this->X = X;
	this->sila = 0;
	this->inicjatywa = 0;
	this->wiek = 1;
	this->stan = true;
	this->rozmnozylSie = false;
}

void Guarana::Kolizja(Organizm* atakujacy) {

	std::string na_polu = GetNazwaKlasy(typeid(*this).name());

	std::string wchodzacy = GetNazwaKlasy(typeid(*atakujacy).name());

	std::string komentarz = "";

	if (atakujacy->GetSila() >= this->GetSila()) {
		this->stan = MARTWY;
		atakujacy->SetSila(atakujacy->GetSila() + 3);

		komentarz = wchodzacy + " zjadl " + na_polu + " na polu " 
			+ std::to_string(this->GetX()) + ' ' + std::to_string(this->GetY());
	}
	else if (atakujacy->GetSila() < this->GetSila()) {
		atakujacy->SetStan(MARTWY);

		komentarz = wchodzacy + " probowal zjesc i nie dal rady " + na_polu + " na polu " 
			+ std::to_string(this->GetX()) + ' ' + std::to_string(this->GetY());
	}

	this->swiat->DodajKomentarz(komentarz);
}