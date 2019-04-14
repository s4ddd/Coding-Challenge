/*
 * Script for checking that the output file
 * is a correct answer for the input file used
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>


int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Please enter a value" << std::endl;
		return 0;
	}

	std::string file_name = argv[1];

	std::unordered_map<long long, int> m;
	std::string line;

	std::ifstream f1(file_name + ".in");

	int line_num = 0;
	if (f1.is_open()) {
		line_num = 0;
		while (getline(f1, line)) {
			if (line_num != 0) {
				// store all the numbers found
				// and the frequency of their occurrence
				auto it = m.find(std::stoll(line));
				if (it == m.end()) m.emplace(std::stoi(line), 1);
				else ++(it->second);
			}
			++line_num;
		}
		f1.close();
	}

	int count = 0;
	long long prevNum = -1;
	long long prev, curr; 
	std::ifstream f2(file_name + ".out");
	line_num = -1;
	if (f2.is_open()) {
		while (getline(f2, line)) {
			++line_num;
			curr = std::stoll(line);
			if (line_num != 0) {
				// count the number of times a number repeats itself
				if (prev != curr) {
					if (m.find(prev) == m.end()) {
						std::cout << "Test " << file_name << " failed: ";
						std::cout << "Invalid number " << std::endl;
						f2.close();
						return 0;
					}
					if (m[prev] != count) {
						std::cout << "Test " << file_name << " failed: ";
						std::cout << "Invalid frequency for " << prev << ". " << m[prev] << " should be " << count << std::endl;
						f2.close();
						return 0;
					}
					// and if the number has changed (not for the first time)
					if (prevNum != -1) {
						// check that, if the prev(ious) 'number' occurs as much as 
						// its' previous 'number', the prev(ious) number is larger
						if (m[prevNum] == m[prev]) {
							if (prevNum > prev) {
								std::cout << "Test " << file_name << " failed: "
								          << "at line " << line_num
								          << " Numbers with less value should appear "
								          << "first if it's frequency is the same" << std::endl;
								f2.close();
								return 0;
							}
						// otherwise check that the prev(ious) 'number' occurs 
						// more often than its' previous number
						}

						if (m[prevNum] > m[prev]) {
							std::cout << "Test " << file_name << " failed";
							std::cout << " Numbers with lower frequency "
							          << "should appear first" << std::endl;
							f2.close();
							return 0;
						}

					}
					prevNum = prev;
					count = 0;
				}
			}
			prev = curr;
			++count;
		}
		if (m.find(prev) == m.end()) {
			std::cout << "Test " << file_name << " failed: ";
			std::cout << "Invalid number " << std::endl;
			f2.close();
			return 0;
		}
		if (m[prev] != count) {
			std::cout << "Test " << file_name << " failed: ";
			std::cout << "Invalid frequency for " << prev << ". " << m[prev] << " should be " << count << std::endl;
			f2.close();
			return 0;
		}

		f2.close();	
	}
	// std::cout << "Test " << file_name << " passed" << std::endl;

	return 0;
}