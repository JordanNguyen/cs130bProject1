#ifndef POINT_H
#define POINT_H
#include <math.h>
#include <iostream>

class Point {
	private:
		float x;
		float y;

	public:
		Point(float xcor, float ycor) { x = xcor; y = ycor; }

		~Point() {}

		float getDistance(Point other) {
			float xs = (x - other.getX()) * (x - other.getX()); //(x2 - x1)^2
			float ys = (y - other.getY()) * (y - other.getY()); //(y2 - y1)^2
			return sqrt(xs + ys);                          
		}

		float getX()	{return x;}
		float getY()	{return y;}
		void toString() { std::cout << "(" << x << "," << y << ")" << std::endl; }

};

#endif

