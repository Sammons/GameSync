#pragma once

#include "common.h"

class Coord
{
public:
	Coord(double x, double y);
	~Coord();
	
	Coord operator+(const Coord& pos) const;
	Coord& operator+=(const Coord& pos);
	Coord operator-(const Coord& pos) const;
	Coord& operator-=(const Coord& pos);
	Coord operator*(double x) const;
	Coord& operator*=(double x);
	Coord operator-() const;

	bool operator==(const Coord& pos) const;
	bool operator!=(const Coord& pos) const;

	void applyAngle(double angle);
	double det(const Coord& pos);

	/* data */
	double x;
	double y;
};