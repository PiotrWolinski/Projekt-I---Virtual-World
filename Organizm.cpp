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

int Organizm::GetSila() const {
	return this->sila;
}

void Organizm::SetSila(const int sila){
	this->sila = sila;
	}

int Organizm::GetInicjatywa() const {
	return this->inicjatywa;
}

void Organizm::SetInicjatywa(const int inicjatywa) {
	this->inicjatywa = inicjatywa;
}

int Organizm::GetWiek() const {
	return this->wiek;
}

void Organizm::SetWiek(int wiek) {
	this->wiek = wiek;
}

bool Organizm::GetStatus() const {
	return this->zywy;
}

void Organizm::SetStatus(bool const status) {
	this->zywy = status;
}