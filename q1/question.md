An array of integers ​_arr_ , of size _n_​ is defined as [​_a[0], a[1], ..., a[n-1]_ . You will be given an array of integers to sort. Sorting must first be by frequency of occurrence, then by value. For instance, given an array [4, 5, 6, 5, 4, 3], there is one each of 6's and 3's, and there are two 4's, two 5's. The sorted list is [3, 6, 4, 4, 5, 5].

## Function Description
Complete the function ​_customSort_​ in the editor below. The function must print the array each element on a separate line, sorted ascending first by frequency of occurrence, then by value within frequency.

customSort has the following parameter(s):
_arr[ arr[0],​ ...arr[n-1] ]:_​ an array of integers to sort

## Constraints
- 1 ≤ n ≤ 2 × 10 ​ 5
- 1 ≤ arr[i] ≤ 10 6 ​

## Input Constraints
Input from stdin will be processed as follows and passed to the function.
- The first line contains an integer ​_n_​ , the size of the integer array ​_arr_ .
- The next ​_n_​ lines each contain an element ​_arr[i]_​ .

## Sample Input 0
`
5
3
1
2
2
4
`

## Sample Output 0
`
1
3
4
2
2
`