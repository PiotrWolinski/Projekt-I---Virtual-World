#pragma once

class Wspolrzedne
{
	int x;
	int y;
public:
	int GetX() const;
	int GetY() const;
	void SetX(const int x);
	void SetY(const int y);

	bool operator==(const Wspolrzedne& other);
	bool operator!=(const Wspolrzedne& other);

	Wspolrzedne LosujPunkt(const int maxY, const int maxX, const int minY, const int minX);
	Wspolrzedne ZwrocSasiadujacy(const Wspolrzedne& other, int maxY, int maxX);

};

