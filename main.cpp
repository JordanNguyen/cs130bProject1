#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <cfloat>
#include <algorithm>
#include "Point.h"
#include "helper.h"
#include "Pair.h"

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

		std::vector<Point> result = getPoints();
		if (result.size() < 2)
		{
			std::cout << "Not enough points to compute closest pair. Program closing." << std::endl;
			return -1;
		}

		else
		{
	    //bruteForce(result);
	    printPairs(bruteForcePairs(result));
	    return 0;
	  //   std::sort(result.begin(), result.end(), compareY());
			// for (int i = 0; i < result.size(); i++)
			// {
			// 	result[i].toString();
			// 	std::cout << std::endl;
			// }
			// return 0;
		}

	}

		else if (option == "basic")
		{
			std::vector<Point> result = getPoints();
			if (result.size() < 2)
			{
				std::cout << "Not enough points to compute closest pair. Program closing." << std::endl;
				return -1;
			}

			else
			{
				//std::cout << "entering basic sort alg" << std::endl;
		    basicSort(result);
		    return 0;
			}

		}
		else if (option == "optimal")
		{
			std::vector<Point> result = getPoints();
			if (result.size() < 2)
			{
				std::cout << "Not enough points to compute closest pair. Program closing." << std::endl;
				return -1;
			}

			else
			{
				//std::cout << "entering basic sort alg" << std::endl;
		    optimalSort(result);
		    return 0;
			}
		}
	}
