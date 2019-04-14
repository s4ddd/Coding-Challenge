/*
 * Solution implementation
 * to compile: g++ -Wall -Werror -o solution solution.cpp
 * to run: ./solution.cpp < [path to input.in file from current directory]
*/


#include <iostream>
#include <math.h>

#define MOD 1000000007

#define MAXN 2000000000
#define MAXK 4000000000000000

unsigned long long maxMoney(
	unsigned long long numStudents, unsigned long long unlucky) {
	// Calculate sum of numbers from 1 to numStudents:
	// i.e. 1 + 2 + ... + n = (1+n)*n/2;
	unsigned long long a = numStudents + 1;
	unsigned long long b = numStudents;
	if (a % 2 == 0) {
		a = (a >> 1);
	} else {
		b = (b >> 1);
	}
	unsigned long long maxMoney = a * b;
	
	// if the unlucky number is 1, then we return 2 + 3 + ... + n;
	if (unlucky == 1) return (maxMoney-1) % MOD;
	if (unlucky > maxMoney) return maxMoney % MOD;
	
	/* ======================= NOTE =======================
	 * Given that 1 + 2 + ... + n = (1+n)*n/2,
	 * let u = unlucky = 1 + 2 + ... + n
	 *     then, u = (1+n)*n/2, which expands to
	 *           n*n + n - 2u = 0; (1)
	 *
	 * Applying the quadratic equation to (1) to find valid values of n gives,
	 *           x1 = (-1 + sqrt(1 + 8u))/2
	 *           x2 = (-1 - sqrt(1 + 8u))/2
	 *    (i.e. x1*x1 + x1 - 2u == 0 x2*x2 + x2 - 2u == 0)
	 *
	 * In the context of 1 + 2 + ... + n = (1+n)*n/2,
	 *    1 + n is the equivalent of abs(x2) and,
	 *        n is the equivalent of abs(x1);
	 *
	 * Therefore, if u were to be a sum of 1 to n, for any integer n,
	 *   x1 and x2 must be whole numbers and sqrt(1 + 8u) cannot be 
	 *   a floating-point-decimal.
	 */

	long double d = std::sqrt(1 + (unlucky << 3));
	a = d; // take the integer value of d

	// So, if the sqrt is not a whole number, unlucky is never countered
	if (a != d) return maxMoney % MOD;
	
	// otherwise, removing student 1's amount will suffice
	return (maxMoney-1) % MOD;
}

int main() {
	unsigned long long numStudents; // 1 <= n <= 2 * 10^9
	unsigned long long unlucky;     // 1 <= k <= 4 * 10^15
	std::cin >> numStudents >> unlucky;
	
	if (numStudents < 1 || numStudents > MAXN) {
		std::cout << "Please enter a value between 1 and 2*10^9 (inclusive)" << std::endl;
		return 0;
	}
	
	if (unlucky < 1 || unlucky > MAXK) {
		std::cout << "Please enter a value between 1 and 4*10^15 (inclusive)" << std::endl;
		return 0;
	}

	std::cout << maxMoney(numStudents, unlucky) << std::endl;
	return 0;
}