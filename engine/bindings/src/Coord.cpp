#include "Coord.h"

Coord::Coord(double x, double y): x(x), y(y) {
}

Coord::~Coord() {

}

Coord Coord::operator+(const Coord& coord) const {
	return Coord(x + coord.x, y + coord.y);
}

Coord& Coord::operator+=(const Coord& coord) {
	x += coord.x;
	y += coord.y;
	return *this;
}

Coord Coord::operator-(const Coord& coord) const {
	return Coord(x - coord.x, y - coord.y);
}

Coord& Coord::operator-=(const Coord& coord) {
	x -= coord.x;
	y -= coord.y;
	return *this;
}

Coord Coord::operator*(double scale_factor) const {
	return Coord(x * scale_factor, y * scale_factor);
}

Coord& Coord::operator*=(double scale_factor) {
	x *= scale_factor;
	y *= scale_factor;
	return *this;
}

Coord Coord::operator-() const {
	return Coord(-x, -y);
}

bool Coord::operator==(const Coord& coord) const {
	return (x == coord.x && y == coord.y);
}

bool Coord::operator!=(const Coord& coord) const {
	return !(*this == coord);
}

void Coord::applyAngle(double angle) {

}

//Calculates the determinant of two Coordinates
double Coord::det(const Coord& c) {
	return (this->x)*(c.y)-(this->y)*(c.x);
}