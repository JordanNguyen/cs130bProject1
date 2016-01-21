#ifndef POINT_H
#define POINT_H
#include <cmath>
#include <iostream>

class Point {
private:
public:
	double x;
	double y;

	Point(double xcor, double ycor) { x = xcor; y = ycor; }
	Point() {x = 0; y = 0;}
	~Point() {}
	void toString() { std::cout << "(" << x << ", " << y << ")"; }

	bool operator==(Point p1)
	{
		if ((fabs(p1.x - x) < .0000001) && (fabs(p1.y - y) < .0000001))
			return true;
		else
			return false;
	}
};

#endif

