#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <cfloat>
#include "Point.h"


/* still need to implement case with <2 or >2 inputs given */
std::vector<Point> getPoints() {

	std::vector<Point> myVector;
	std::string line;
	while (std::getline(std::cin, line))
	{
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

	return myVector;
}

double distance(Point p1, Point p2) {
	
	double xs = pow((p2.x - p1.x),2);
	double ys = pow((p2.y - p1.y),2);
	return sqrt(xs + ys);
}

void printPairs(std::vector<Point> pairs, int dist) {
	
	std::cout << "closest pair distance: " << dist << std::endl;
	for (int i = 0; i < pairs.size(); i = i+2) {
		pairs[i].toString();
		std::cout << " ";
		pairs[i+1].toString();
		std::cout << std::endl;
	}
}

/* need to implement way to return multiple pairs  
   -push points to vector if new min distance found. 
   -if new min distance found, clear the vector and push new
   -if same min distance is found, push to vector 
   -implement a print function so it prints the pairs in order */
void bruteForce(std::vector<Point> points) {
	
	std::vector<Point> pair;
	double minDistance = DBL_MAX;
	int n = points.size();
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (distance(points[i],points[j]) < minDistance) //new min found, clear vector
			{
				minDistance = distance(points[i], points[j]);
				pair.clear();
				if (points[i].x < points[j].x) //compare x values. i then j
				{
					pair.push_back(points[i]);
					pair.push_back(points[j]);
				}
				else if (points[i].x > points[j].x) //j then i
				{
					pair.push_back(points[j]);
					pair.push_back(points[i]);
				}
				else if (points[i].x == points[j].x && points[i].y < points[j].y) //compare y values if x are same
				{
					pair.push_back(points[i]);
					pair.push_back(points[j]);
				}
				else if (points[i].x == points[j].x && points[i].y > points[j].y) 
				{
					pair.push_back(points[j]);
					pair.push_back(points[i]);
				}
			}

			else if (distance(points[i],points[j]) == minDistance) //another min pair found, add to vector
			{
				if (points[i].x < points[j].x) //compare x values. i then j
				{
					pair.push_back(points[i]);
					pair.push_back(points[j]);
				}
				else if (points[i].x > points[j].x) //j then i
				{
					pair.push_back(points[j]);
					pair.push_back(points[i]);
				}
				else if (points[i].x == points[j].x && points[i].y < points[j].y) //compare y values if x are same
				{
					pair.push_back(points[i]);
					pair.push_back(points[j]);
				}
				else if (points[i].x == points[j].x && points[i].y > points[j].y) 
				{
					pair.push_back(points[j]);
					pair.push_back(points[i]);
				}
			}
		}
	}	
	
	return printPairs(pair, minDistance);
}



#endif