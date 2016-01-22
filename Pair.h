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
	bool operator==(Pair pt)
	{
		if ((fabs(pt.p1.x - p1.x) < .0000001) && (fabs(pt.p1.y - p1.y) < .0000001))
			return true;
		else
			return false;
	}

	bool operator<(const Pair &pair2) const
	{
		if (p1.x < pair2.p1.x)
			return true;
		else if (p1.x > pair2.p1.x)
			return false;
		else if (fabs(p1.x - pair2.p1.x) < .0000001)
			{
				if (p1.y < pair2.p1.y)
					return true;
				else
					return false;
			}
	}

};

#endif