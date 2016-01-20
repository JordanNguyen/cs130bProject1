#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <cfloat>
#include "Point.h"
#include "helper.h"

int main(int argc, char *argv[]) {

	if (argc != 2)
	{
		std::cout <<"Usage: ./closestPair [brute|basic|optimal]" << std::endl;
		return -1;
	}

	std::string option = argv[1];

	if (option != "brute" && option != "basic" && option != "optimal")
	{
		std::cout <<"Usage: ./closestPair [brute|basic|optimal]" << std::endl;
		return -1;
	}
	
	else if (option == "brute")
	{
	  //bruteForce(getPoints());
	  std::vector<Point> test = getPoints();
	  for (int i = 0; i < test.size(); i++)
	    {
	      test[i].toString();
	      std::cout << std::endl;
	    }
		return 0;
	}

	else if (option == "basic")
	{
		return -1;
	}

	else if (option == "optimal")
	{
		return -1;
	}
}
