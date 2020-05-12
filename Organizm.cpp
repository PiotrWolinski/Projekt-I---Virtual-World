#include "Organizm.h"
#include <cstdlib>
#include <utility>

void Organizm::SetSwiat(Swiat *swiat) {
	this->swiat = swiat;
}

Swiat* Organizm::GetSwiat() const {
	return this->swiat;
}

int Organizm::GetX() const {
	return this->X;
}

void Organizm::SetX(const int X) {
	this->X = X;
}

int Organizm::GetY() const {
	return this->Y;
}

void Organizm::SetY(const int X) {
	this->Y = Y;
}