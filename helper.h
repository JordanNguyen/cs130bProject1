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
#include <algorithm>
#include <set>
#include "Point.h"
#include "Pair.h"

const double tolerance = .0000001;

double distance(Point p1, Point p2) {
	
	double xs = pow((p2.x - p1.x),2);
	double ys = pow((p2.y - p1.y),2);
	return sqrt(xs + ys);
}

std::vector<Pair> minPair(std::vector<Pair> pairs1, std::vector<Pair> pairs2)
{
	// std::cout << "entered min pair with pairs1 size " << pairs1.size() << " and pairs2 size " << pairs2.size() << std::endl;
	if (pairs1.size() == 0 && pairs2.size() == 0)

	if (pairs1.size() == 0 && pairs2.size() != 0)
	{
		// std::cout <<"pairs2 return from minPair" << std::endl;
		return pairs2;
	}

	if (pairs1.size() != 0 && pairs2.size() == 0)
	{
		// std::cout <<"pairs1 return from minPair" << std::endl;
		return pairs1;
	}

	if (fabs(distance(pairs1[0].p1, pairs1[0].p2) - distance(pairs2[0].p1, pairs2[0].p2)) < tolerance)
	{
		// std::cout << "same dist" << std::endl;
		std::vector<Pair> combined = pairs1;
		// std::cout << "combined = pairs1" << std::endl;
		for (int i = 0; i < pairs2.size(); i++)
		{
			combined.push_back(pairs2[i]);
		}
		// std::cout << "return combined size " << combined.size() << std::endl;
		return combined;
	}

	else if (distance(pairs1[0].p1, pairs1[0].p2) < distance(pairs2[0].p1, pairs2[0].p2))
	{
		// std::cout << "exit min pair" << std::endl;
		return pairs1;
	}
	else if (distance(pairs1[0].p1, pairs1[0].p2) > distance(pairs2[0].p1, pairs2[0].p2))
	{
		// std::cout << "exit min pair" << std::endl;
		return pairs2;
	}
	
}

struct compareX
{
	inline bool operator() (const Point &p1, const Point &p2)
	{
		if (p1.x < p2.x)
			return true;
		else if (p1.x > p2.x)
			return false;
		else if (fabs(p1.x - p2.x) < tolerance)
		{
			if (p1.y < p2.y)
				return true;
			else
				return false;
		}
	}
};

struct compareY
{
	inline bool operator() (const Point &p1, const Point &p2)
	{
		if (p1.y < p2.y)
			return true;
		else if (p1.y > p2.y)
			return false;
		else if (fabs(p1.y - p2.y) < tolerance)
		{
			if (p1.x < p2.x)
				return true;
			else
				return false;
		}
	}
};

struct comparePairs
{
	inline bool operator() (const Pair &pair1, const Pair &pair2)
	{
		if (pair1.p1.x < pair2.p1.x)
			return true;
		else if (pair1.p1.x > pair2.p1.x)
			return false;
		else if (fabs(pair1.p1.x - pair2.p1.x) < tolerance)
			{
				if (pair1.p1.y < pair2.p1.y)
					return true;
				else
					return false;
			}
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

std::vector<Point> removeDupes(std::vector<Point> points)
{

	std::set<Point> s;
	int size = points.size();
	for (int i = 0; i < size; i++)
		s.insert(points[i]);
	points.assign(s.begin(), s.end());

	return points;

}

std::vector<Pair> removeDupesPair(std::vector<Pair> points)
{

	std::set<Pair> s;
	int size = points.size();
	for (int i = 0; i < size; i++)
		s.insert(points[i]);
	points.assign(s.begin(), s.end());

	return points;

}

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
		
		myVector.push_back(Point(first,second));
	}

	return removeDupes(myVector);
}

void printPairs(std::vector<Pair> pairs) {
	
	pairs = removeDupesPair(pairs);
	std::sort(pairs.begin(), pairs.end(), comparePairs());
	std::cout.precision(7);
	std::cout << "closest pair distance: " << distance(pairs[0].p1,pairs[0].p2) << std::endl;
	for (int i = 0; i < pairs.size(); i++) {
		if (distance(pairs[i].p1, pairs[i].p2) - distance(pairs[0].p1,pairs[0].p2) < .0000001)
		{	
			pairs[i].toString();
			std::cout << std::endl;
		}
	}
}


std::vector<Pair> bruteForcePairs(std::vector<Point> points)
{
	// std::cout << "entered brute force with " << points.size() << "points" << std::endl;
	std::vector<Pair> pairs;
	double minDistance = DBL_MAX;
	int n = points.size();
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (fabs(distance(points[i],points[j]) - minDistance) < tolerance) //another min pair found, add to vector
			{
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
			else if (distance(points[i],points[j]) < minDistance) //new min found, clear vector
			{
				
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
		}
	}	
	// std::cout << "exit brute force with " << pairs.size() << "pairs" << std::endl;
	return pairs;
}

std::vector<Pair> stripClosest(std::vector<Point> points, int size, double d)
{
	// std::cout << "entered stripclosest with vector sized" << points.size() << std::endl;
	double min = d;
	std::vector<Pair> pairs;
	std::sort(points.begin(), points.end(), compareY());

	for (int i = 0; i < size; i++) {
			for (int j = i+1; j < size && (points[j].y - points[i].y) <= min; j++) {
				if (fabs(distance(points[i],points[j]) - min) < tolerance) //another min pair found, add to vector
				{

					if (points[i].x < points[j].x) //compare x values. i then j
					{
						pairs.push_back(Pair(points[i], points[j]));
						// std::cout << "pushing pair case 1" << std::endl;
					}
					else if (points[i].x > points[j].x) //j then i
					{
						pairs.push_back(Pair(points[j], points[i]));
						// std::cout << "pushing pair case 2" << std::endl;
					}
					else if (points[i].x == points[j].x && points[i].y < points[j].y) //compare y values if x are same
					{
						pairs.push_back(Pair(points[i], points[j]));
						// std::cout << "pushing pair case 3" << std::endl;
					}
					else if (points[i].x == points[j].x && points[i].y > points[j].y) 
					{
						pairs.push_back(Pair(points[j], points[i]));
						// std::cout << "pushing pair case 4" << std::endl;
					}
				}
				else if (distance(points[i],points[j]) < min)
				{
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
			}
		}	
	
	//std::cout << "exit strip closest with vector sized " << pairs.size() << std::endl;
	return pairs;	
}

std::vector<Pair> stripClosestOpt(std::vector<Point> points, int size, double d)
{
	// std::cout << "entered stripclosest with vector sized" << points.size() << std::endl;
	double min = d;
	std::vector<Pair> pairs;

	for (int i = 0; i < size; i++) {
			for (int j = i+1; j < size && (points[j].y - points[i].y) <= min; j++) {
				if (fabs(distance(points[i],points[j]) - min) < tolerance) //another min pair found, add to vector
				{

					if (points[i].x < points[j].x) //compare x values. i then j
					{
						pairs.push_back(Pair(points[i], points[j]));
						// std::cout << "pushing pair case 1" << std::endl;
					}
					else if (points[i].x > points[j].x) //j then i
					{
						pairs.push_back(Pair(points[j], points[i]));
						// std::cout << "pushing pair case 2" << std::endl;
					}
					else if (points[i].x == points[j].x && points[i].y < points[j].y) //compare y values if x are same
					{
						pairs.push_back(Pair(points[i], points[j]));
						// std::cout << "pushing pair case 3" << std::endl;
					}
					else if (points[i].x == points[j].x && points[i].y > points[j].y) 
					{
						pairs.push_back(Pair(points[j], points[i]));
						// std::cout << "pushing pair case 4" << std::endl;
					}
				}
				else if (distance(points[i],points[j]) < min)
				{
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
			}
		}	
	
	//std::cout << "exit strip closest with vector sized " << pairs.size() << std::endl;
	return pairs;	
}

std::vector<Pair> basicSortRec(std::vector<Point> points) {

	//std::cout << "entered recursive with " << points.size() << std::endl;

	if (points.size() <= 3)
	{
		//std::cout << "reached base case" << std::endl;
		return bruteForcePairs(points);
	}

	int mid = points.size()/2;
	Point middle = points[mid];

	std::vector<Point>::const_iterator first = points.begin();
	std::vector<Point>::const_iterator last  = points.begin() + mid;
	std::vector<Point> leftPoints(first, last);
	//std::cout << "leftPoints is size " <<leftPoints.size() <<std::endl;
	std::vector<Point>::const_iterator first2 = points.begin() + mid + 1;
	std::vector<Point>::const_iterator last2  = points.end();
	//std::cout << "entered recursive left" << std::endl;
	std::vector<Pair> minLeft  = basicSortRec(leftPoints);
	std::vector<Point> rightPoints(first2, last2);
	//std::cout << "rightPoints is size " <<leftPoints.size() <<std::endl;

	// std::cout << "entered recursive right" << std::endl;
	std::vector<Pair> minRight = basicSortRec(rightPoints);

	///std::vector<Pair> minBoth = minPair(basicSortRec(leftPoints), basicSortRec(rightPoints));
	std::vector<Pair> minBoth = minPair(minLeft, minRight);
	//std::cout << "exit min pair" << std::endl;

	std::vector<Point> strip;
	//std::cout << "enter for loop for strip" << std::endl;
	// std::cout << "distance of minBoth is " << distance(minBoth[0].p1, minBoth[0].p2) << std::endl;
	for (int i = 0; i < points.size(); i++)
	{
		if ((fabs(points[i].x - middle.x)) <= distance(minBoth[0].p1, minBoth[0].p2))
		{
			strip.push_back(points[i]);
		}
	}
	return minPair(minBoth, stripClosest(strip, strip.size(), distance(minBoth[0].p1, minBoth[0].p2)));

}

std::vector<Pair> optimalSortRec(std::vector<Point> pointsx, std::vector<Point> pointsy)
{

	if (pointsx.size() <= 3)
	{
		return bruteForcePairs(pointsx);
	}

	int mid = pointsx.size()/2;
	Point middle = pointsx[mid];

	std::vector<Point>::const_iterator first = pointsx.begin();
	std::vector<Point>::const_iterator last  = pointsx.begin() + mid;

	std::vector<Point> leftX(first, last);
	// std::cout <<"created leftX"<<std::endl;
	std::vector<Point>::const_iterator first2 = pointsx.begin() + mid + 1;
	std::vector<Point>::const_iterator last2  = pointsx.end();
	// std::cout << "entered recursive left" << std::endl;
	std::vector<Point> rightX(first2, last2);
	// std::cout <<"created rightX"<<std::endl;
	std::vector<Point> leftPointsY;
	std::vector<Point> rightPointsY;
	for (int i = 0; i < pointsy.size(); i++)
	{
		if (pointsy[i].x <= middle.x)
			leftPointsY.push_back(pointsy[i]);
		else
			rightPointsY.push_back(pointsy[i]);
	}

	std::vector<Pair> minLeft = optimalSortRec(leftX,leftPointsY);
	std::vector<Pair> minRight = optimalSortRec(rightX,rightPointsY);

	std::vector<Pair> minBoth = minPair(minLeft, minRight);

	std::vector<Point> strip;
	for (int i = 0; i < pointsy.size(); i++)
	{
		if ((fabs(pointsy[i].x - middle.x)) <= distance(minBoth[0].p1, minBoth[0].p2))
		{
			strip.push_back(pointsy[i]);
		}
	}
	return minPair(minBoth, stripClosestOpt(strip, strip.size(), distance(minBoth[0].p1, minBoth[0].p2)));
}


void basicSort(std::vector<Point> points)
{

	std::sort(points.begin(), points.end(), compareX());

	printPairs(basicSortRec(points));
}

void optimalSort(std::vector<Point> points)
{
	std::vector<Point> pointsx = points;
	std::vector<Point> pointsy = points;

	std::sort(pointsx.begin(), pointsx.end(), compareX());
	std::sort(pointsy.begin(), pointsy.end(), compareY());

	printPairs(optimalSortRec(pointsx, pointsy));
}



#endif
