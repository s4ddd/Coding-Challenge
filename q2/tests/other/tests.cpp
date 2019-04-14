#include <iostream>
#include <fstream>
#include <string>

#define MOD 1000000007
#define MAXN 2000000000
#define MAXK 4000000000000000
#define LIM 20

unsigned long long generateBruteForceSolution
	(unsigned long long n, unsigned long long k) {
	unsigned long long i, m = 0;
	unsigned long long dec = 1;
	for (i = 1; i <= n; ++i) {
		if (m + i == k) {
			m -= dec;
			++dec;
		};
		m += i;
	}
	return (m % MOD);
}


int main() {
	unsigned long long n, k, i = 0;
	unsigned long long fd = 0;
	std::ofstream f;
	std::string x;           
	for (n = 1; n <= MAXN; ++n) {
		if (n == LIM) n = MAXN-LIM;
		for(k = 1; k <= MAXK; ++k) {
			if (k == LIM) k = MAXK-LIM;
			if (i % 500 == 0) fd = i;

			x = std::to_string(i);
			
			f.open(std::to_string(fd) + "/" + x + ".in");
			f << n << "\n" << k << "\n";
			f.close();

			f.open(std::to_string(fd) + "/" + x + ".out");
			f << generateBruteForceSolution(n, k) << "\n";
			f.close();

			++i;
		}
	}

	return 0;
}