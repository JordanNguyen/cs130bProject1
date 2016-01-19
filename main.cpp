#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <float.h>
#include "Point.h"

float distance(Point p1, Point p2) {
	float xs = (p2.getX() - p1.getX()) * (p2.getX() - p1.getX());
	float ys = (p2.getY() - p1.getY()) * (p2.getY() - p1.getY());
	return sqrt(xs + ys);
}

float bruteForce(std::vector<Point> points) {
	std::cout << "entering brute force" << std::endl;
	float smallestDistance = FLT_MAX;
	int n = points.size();
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (distance(points[i],points[j]) < smallestDistance)
				smallestDistance = distance(points[i], points[j]);
	}
}

	return smallestDistance;

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
		float first;
		float second;
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

	float min = bruteForce(myVector);
	std::cout << "closest pair distance: " << min << std::endl; 
}
