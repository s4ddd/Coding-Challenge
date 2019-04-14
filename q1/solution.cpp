/*
 * Solution implementation
 * to compile: g++ -Wall -Werror -o solution solution.cpp
 * to run: ./solution.cpp < [path to input.in file from current directory]
*/



#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>

#define MAXN 200000
#define MAXV 1000000


void customSort(std::list<int>& arr) {
	std::pair<int, int> nums[arr.size()];
	std::unordered_map<int, std::pair<int, int>*> mapping;

	/* Example of how [3, 1, 2, 2, 4] is stored:
     * mapping              nums
     *  key: 3  value: ---> [<3, 1>]   (where the first value of each pair
     *  key: 1  value: ---> [<1, 1>]    is the number, and the second value,
     *  key: 2  value: ---> [<2, 2>]    its' frequency
     *  key: 4  value: ---> [<4, 1>]6c                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

     * An unordered map is used because searching and inserting an element,
     * on average, takes constant time, but it cannot be sorted directly.
     * An array is thus used and contains the variables needed for the 
     * sorting to happen.
	 */


	std::unordered_map<int, std::pair<int, int>*>::iterator it;

	int i, j, n = 0;

	// for each value in the list of given numbers
	for (int x : arr) {
		it = mapping.find(x);
		// if this number has not been encountered before
		if (it == mapping.end()) {
			// store the number and 1 as its frequency
			nums[n] = std::make_pair(x, 1);
			// and create a mapping between
			// the number (as the key value)
			// and the address of that number's entry in the array
			mapping.emplace(x, &nums[n]);

			++n; // increment to the next available entry in the array

		} else {
			// otherwise increment the frequency
			++(it->second->second);
		}
	}

	// use the in-built quicksort, but customise comparator function
	std::sort(nums, nums+n, []
		(std::pair<int, int> &a, std::pair<int, int> &b) {
			// if the frequency is the same,
			// the number with the lower value goes first
			if (a.second == b.second) return (a.first < b.first);
			// otherwise the number with the lower frequency goes first
			return(a.second < b.second);
		}
	);

	// print the list
	for (i = 0; i < n; ++i) {
		for (j = 0; j < nums[i].second; ++j) {
			std::cout << nums[i].first << std::endl;
		}
	}
}


int main() {
	int n, m;
	std::cin >> n;
	if (n < 1 || n > MAXN) {
		std::cout << "Please enter a value between 1 and 2*10^5 (inclusive)" << std::endl;
		return 0;
	}
	
	std::list<int> v;
	for (int i = 0; i < n; ++i) {
		std::cin >> m;
		if (m < 1) {
			std::cout << "the value of M has been changed to 1" << std::endl;
			return 0;
		}
		if (m > MAXV) {
			std::cout << "the value of M has been changed to " << MAXV << std::endl;
			return 0;
		}

		v.emplace_back(m);
	}

	customSort(v);

	return 0;
}