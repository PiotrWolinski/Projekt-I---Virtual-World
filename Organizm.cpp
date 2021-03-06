#include "Organizm.h"
#include <cstdlib>
#include <utility>
#include <string>
#include <sstream>

char Organizm::GetSymbol() const {
	return this->symbol;
}

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

void Organizm::SetY(const int Y) {
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

bool Organizm::GetStan() const {
	return this->stan;
}

void Organizm::SetStan(bool const status) {
	this->stan = status;
}

void Organizm::SetLastX(int const X) {
	this->lastX = X;
}

int Organizm::GetLastX() const {
	return this->lastX;
}

void Organizm::SetLastY(int const Y) {
	this->lastY = Y;
}

int Organizm::GetLastY() const {
	return this->lastY;
}

void Organizm::SetRozmnozylSie(bool const rozmnozylSie) {
	this->rozmnozylSie = rozmnozylSie;
}

bool Organizm::GetRozmnozylSie() const{
	return this->rozmnozylSie;
}

std::string Organizm::GetNazwaKlasy(std::string nazwa) {
	std::istringstream ss(nazwa);
	std::string slowo;
	ss >> slowo;
	ss >> slowo;
	return slowo;
}

std::string Organizm::ToString() {
	std::string out;
	out = std::to_string(symbol) + " " + std::to_string(X) + " " + std::to_string(Y) + " " + std::to_string(sila) + " " 
		+ std::to_string(wiek) + " " + std::to_string(lastX) + " " + std::to_string(lastY) + " " + std::to_string(stan)+ " " 
		+ std::to_string(rozmnozylSie);

	return out;
}