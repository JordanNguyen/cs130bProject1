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

	bool operator!=(Point p1)
	{
		if ((fabs(p1.x - x) < .0000001) && (fabs(p1.y - y) < .0000001))
			return false;
		else
			return true;
	}

	bool operator<(const Point &p1) const
	{
		if (x < p1.x)
			return true;
		else if (x > p1.x)
			return false;
		else if (fabs(x - p1.x) < .0000001)
		{
			if (y < p1.y)
				return true;
			else
				return false;
		}
	}
};

#endif

