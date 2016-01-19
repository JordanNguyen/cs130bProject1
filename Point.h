#ifndef POINT_H
#define POINT_H
#include <math.h>
#include <iostream>

class Point {
	private:
		double x;
		double y;

	public:
		Point(double xcor, double ycor) { x = xcor; y = ycor; }

		~Point() {}

		double getDistance(Point other) {
			double xs = (x - other.getX()) * (x - other.getX()); //(x2 - x1)^2
			double ys = (y - other.getY()) * (y - other.getY()); //(y2 - y1)^2
			return sqrt(xs + ys);                          
		}

		double getX()	{return x;}
		double getY()	{return y;}
		void toString() { std::cout << "(" << x << ", " << y << ")"; }

};

#endif

