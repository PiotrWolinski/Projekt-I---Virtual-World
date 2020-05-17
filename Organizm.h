#pragma once
#include <string>

class Swiat;

class Organizm
{
protected:
	char symbol;
	int sila;
	int inicjatywa;
	int wiek;
	Swiat *swiat;
	int X;
	int Y;
	bool zywy;
	int lastX;
	int lastY;
	bool rozmnozylSie;
public:

	virtual void Akcja() = 0;

	virtual void Kolizja(Organizm* org) = 0;

	virtual void Rysowanie() = 0;

	char GetSymbol() const;

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

	int GetLastX() const;

	void SetLastX(const int X);

	int GetLastY() const;

	void SetLastY(const int Y);

	bool GetRozmnozylSie() const;

	void SetRozmnozylSie(bool const rozmnozylSie);

	std::string GetNazwaKlasy(std::string nazwa);
};

