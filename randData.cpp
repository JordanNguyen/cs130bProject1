#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <cfloat>
#include "Point.h"
#include "helper.h"


void randomInput(int n)
{
	srand(time(NULL));
	int min = -10000;
	int max = 10000;
	for (int i = 0; i < n; i++)
	{
		std::cout << min + (max - min)*(double)rand() / RAND_MAX << " " 
		<< min + (max - min)*(double)rand() / RAND_MAX << std::endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout <<"Usage: ./randData number" << std::endl;
		return -1;
	}

	std::string option = argv[1];
	std::istringstream buffer(option);
	int value;
	buffer >> value; 
	randomInput(value);
	return 0;
}