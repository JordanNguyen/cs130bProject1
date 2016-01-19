#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <float.h>
#include "Point.h"

double distance(Point p1, Point p2) {
	double xs = (p2.getX() - p1.getX()) * (p2.getX() - p1.getX());
	double ys = (p2.getY() - p1.getY()) * (p2.getY() - p1.getY());
	return sqrt(xs + ys);
}

std::vector<Point> bruteForce(std::vector<Point> points) {
	
	std::vector<Point> pair;
	pair.push_back(Point(0,0));
	pair.push_back(Point(0,0));
	double smallestDistance = DBL_MAX;
	int n = points.size();
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (distance(points[i],points[j]) < smallestDistance)
			{
				smallestDistance = distance(points[i], points[j]);
				pair[0] = points[i];
				pair[1] = points[j];
			}
	}
}	

	return pair;

}

int main(int argc, char *argv[]) {

	//vector to store points
	std::vector<Point> myVector;
	//int i = 0;
	std::string line;
	//std::getline(std::cin, line);
	while (std::getline(std::cin, line))
	{
		std::istringstream iss(line);
		double first;
		double second;
		//std::string third;
		iss >> first >> second;
		if (!iss)
		{
			iss.clear();
			continue;
		}
		// if (!third.empty())
		// 	continue;
		myVector.push_back(Point(first,second));
	}
	//std::cout << distance(myVector[0], myVector[1]) << std::endl;
	//std::cout << "You ended the parsing" << std::endl;
	//std::cout << myVector.size() << std::endl;
	
	// std::vector<Point>::iterator it = myVector.begin();
	// int i = 0;
	// while (it != myVector.end()) {
	// 	myVector[i].toString();
	// 	it++;
	// 	i++;
	// }

	std::vector<Point> pair = bruteForce(myVector);
	double min = distance(pair[0], pair[1]);
	std::cout << "closest pair distance: " << min << std::endl; 
	pair[0].toString();
	std::cout << " ";
	pair[1].toString();
	std::cout << std::endl;
}
