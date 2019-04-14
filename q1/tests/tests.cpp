/*
 * Script for generating tests
 * to compile: g++ -Wall -Werror -o tests tests.cpp
 * to run: ./tests
*/


#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

#define MAXN 200000
#define MAXV 1000000
#define NUMTESTS 1000


// Generate 1000 tests of 
// random list length with random numbers
void generateRandom() {
	std::string x;
	std::ofstream f;
	int i, j, n;
	for (i = 1; i <= NUMTESTS; ++i) {
		x = std::to_string(i);
			
		f.open("./random/"+x+".in");
		// number of lines to follow
		n = rand() % MAXN + 1;
		f << n << "\n"; 
		// generate list of random numbers
		for (j = 0; j < n; ++j) {
			f << (rand() % MAXN + 1) << "\n";
		}

		f.close();
	}
}


// Generate 1000 tests of 
// random list length with random combination of 1000 numbers
void generateRepeats() {
	std::string x;
	std::ofstream f;
	int i, j, n;
	int nums[NUMTESTS];
	for (i = 0; i < NUMTESTS; ++i) {
		nums[i] = rand() % MAXN + 1;
		if (nums[i] == 0) {
			std::cout << "help" << std::endl;
		}
	}

	for (i = 1; i <= NUMTESTS; ++i) {
		x = std::to_string(i);
			
		f.open("./repeats/"+x+".in");
		// number of lines to follow
		n = rand() % MAXN + 1;
		f << n << "\n"; 
		// generate list of random numbers
		for (j = 0; j < n; ++j) {
			f << nums[rand() % NUMTESTS] << "\n";
		}

		f.close();
	}
}


int main() {
	generateRandom();
	generateRepeats();
	return 0;
}