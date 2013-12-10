#include "Coord.h"

Coord::Coord(double x, double y) {
	this->x = x;
	this->y = y;
}

Coord::~Coord() {

}

void Coord::add(double x, double y) {
	this->x = this->x+x;
	this->y = this->y+y;
}
void Coord::add(Coord* coord) {
	this->x = coord->x+this->x;
	this->y = coord->y+this->y;
}
void Coord::subtract(Coord* coord) {
	this->x = this->x - coord->x;
	this->y = this->y - coord->y;
}

void Coord::multiply(double x) {
	this->x = this->x * x;
	this->y = this->y * x;
}

bool Coord::equals(double x, double y) {
	if (this->x == x && this->y == y) return true;
	return false;
}
Coord* Coord::clone() {
	return new Coord(this->x, this->y);
}

double Coord::det(Coord* c) {
	return (this->x)*(c->y)-(this->y)*(c->x);
}

void Coord::applyAngle(double angle) {

}