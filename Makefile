main: main.cpp
	clang++ -std=c++11 main.cpp -o closestPair

randData: randData.cpp
	clang++ -std=c++11 randData.cpp -o randData