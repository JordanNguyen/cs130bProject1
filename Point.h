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
		~Point() {}
		void toString() { std::cout << "(" << x << ", " << y << ")"; }

};

#endif

