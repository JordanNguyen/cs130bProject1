#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <cfloat>
#include <iomanip>
#include "Point.h"
#include "Pair.h"


struct compareX
{
	inline bool operator() (const Point &p1, const Point &p2)
	{
		return (p1.x < p2.x);
	}
};

struct compareY
{
	inline bool operator() (const Point &p1, const Point &p2)
	{
		return (p1.y < p2.y);
	}
};

struct comparePairs
{
	inline bool operator() (const Pair &pair1, const Pair &pair2)
	{
		if (pair1.p1.x < pair2.p2.x)
			return true;
		else if (pair1.p1.x == pair2.p2.x)
			return (pair1.p1.y <= pair2.p2.y);
	}
};

struct compareXPairs
{
	inline bool operator() (const Pair &pair1, const Pair &pair2)
	{
		return (pair1.p1.x < pair2.p2.x);
	}
};

struct compareYPairs
{
	inline bool operator() (const Pair &pair1, const Pair &pair2)
	{
		return (pair1.p1.y < pair2.p2.y);
	}
};

bool containsPoint(std::vector<Point> points, Point p)
{
	for (int i = 0; i < points.size(); i++)
	{
		if (p == points[i])
			return true;
	}

	return false;
}

/* still need to implement case with <2 or >2 inputs given */
std::vector<Point> getPoints() {

	std::vector<Point> myVector;
	std::string line;
	while (std::getline(std::cin, line))
	{
		int count = 0;
		std::istringstream check(line);
		std::string input;
		while(check >> input)
			count++;

		if (count > 2)
			continue;

		std::istringstream iss(line);
		double first;
		double second;
		iss >> first >> second;
		if (!iss)
		{
			iss.clear();
			continue;
		}
		if (containsPoint(myVector, Point(first,second)))
			continue;
		else
			myVector.push_back(Point(first,second));
	}

	return myVector;
}

double distance(Point p1, Point p2) {
	
	double xs = pow((p2.x - p1.x),2);
	double ys = pow((p2.y - p1.y),2);
	return sqrt(xs + ys);
}

void printPairs(std::vector<Pair> pairs, double dist) {
	
	std::cout.precision(7);
	std::cout << "number of pairs: " << pairs.size() << std::endl;
	std::cout << "closest pair distance: " << dist << std::endl;
	std::sort(pairs.begin(), pairs.end(), comparePairs());
	for (int i = 0; i < pairs.size(); i++) {
		pairs[i].toString();
		//std::cout << " ";
		//pairs[i+1].toString();
		std::cout << std::endl;
	}
}

/* need to implement way to put pairs in order into vector*/
void bruteForce(std::vector<Point> points) {
	
	std::vector<Pair> pairs;
	double minDistance = DBL_MAX;
	int n = points.size();
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (distance(points[i],points[j]) < minDistance) //new min found, clear vector
			{
				std::cout << "new min dist found" << std::endl;
				minDistance = distance(points[i], points[j]);
				pairs.clear();
				if (points[i].x < points[j].x) //compare x values. i then j
				{
					pairs.push_back(Pair(points[i], points[j]));
				}
				else if (points[i].x > points[j].x) //j then i
				{
					pairs.push_back(Pair(points[j], points[i]));
				}
				else if (points[i].x == points[j].x && points[i].y < points[j].y) //compare y values if x are same
				{
					pairs.push_back(Pair(points[i], points[j]));
				}
				else if (points[i].x == points[j].x && points[i].y > points[j].y) 
				{
					pairs.push_back(Pair(points[j], points[i]));
				}
			}

			else if (fabs(distance(points[i],points[j]) - minDistance) < .0000001) //another min pair found, add to vector
			{
				std::cout << "same min dist found" << std::endl;
				if (points[i].x < points[j].x) //compare x values. i then j
				{
					pairs.push_back(Pair(points[i], points[j]));
				}
				else if (points[i].x > points[j].x) //j then i
				{
					pairs.push_back(Pair(points[j], points[i]));
				}
				else if (points[i].x == points[j].x && points[i].y < points[j].y) //compare y values if x are same
				{
					pairs.push_back(Pair(points[i], points[j]));
				}
				else if (points[i].x == points[j].x && points[i].y > points[j].y) 
				{
					pairs.push_back(Pair(points[j], points[i]));
				}
			}
		}
	}	
	
	return printPairs(pairs, minDistance);
}

double basicSort(std::vector<Point> points)
{
	points.sort(points.begin(), points.)
}



#endif
