#pragma once
#include "Wspolrzedne.h"
//#include "Swiat.h"

class Swiat;

class Organizm
{
protected:
	int id;
	char symbol;
	int sila;
	int inicjatywa;
	int wiek;
	Swiat *swiat;
	int X;
	int Y;
	bool zywy;
public:

	virtual void Akcja() = 0;

	virtual void Kolizja(Organizm* other) = 0;

	virtual void Rysowanie() = 0;

	void SetSwiat(Swiat* swiat);

	Swiat* GetSwiat() const;

	int GetX() const;

	void SetX(const int X);

	int GetY() const;

	void SetY(const int Y);

	int GetSila() const;

	void SetSila(int const sila);

	int GetInicjatywa() const;

	void SetInicjatywa(int const inicjatywa);

	int GetWiek() const;

	void SetWiek(int const wiek);

	bool GetStatus() const;

	void SetStatus(const bool status);

};

