#ifndef PAIR_H
#define PAIR_H
#include <cmath>
#include <iostream>
#include "Point.h"

class Pair {
private:
public:
	Point p1;
	Point p2;

	Pair(Point _p1, Point _p2) { p1 = _p1; p2 = _p2; }
	~Pair() {}
	void toString() { p1.toString(); std::cout << " "; p2.toString(); }

};

#endif