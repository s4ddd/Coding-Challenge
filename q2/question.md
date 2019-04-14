Julia is collecting money from her classmates for a trip. Each classmate has a
unique ID number where ID numbers start at ​_1_​ and increment by ​_1_​ until all classmates
have a number. Each classmate is prepared to donate the number of dollars that
matches their ID, so classmate ​_1_​ can give ​_1_​ dollar, classmate ​_2_​ can give ​_2_​ dollars and
so on. Julia is superstitious, though, and does not ever want to have a sum that
matches her unlucky number. To avoid this, she may refuse a donation from any
classmate. If she visits all of her classmates in ID order, what is the maximum amount
of money she can collect without ever having a number of dollars that matches her
unlucky number? Since the result may be very large, return the result modulo
1000000007 ​ .

For example, there are ​_n = 4_ classmates, and her unlucky number ​_k = 6._ If she collects
from each of her first three classmates, she will have ​_6_ dollars, which is her unlucky
number. To avoid this, she will not collect from at least one classmate, either ​_1, 2_ or ​_3_​ .
If she skips classmate ​_1_​ , she collects ​_2 + 3 + 4 = 9_​ dollars. If she skips number ​_2_​ , she
collects ​_1 + 3 + 4 = 8_​ dollars, and if she skips classmate ​_3_​ , she only collects ​_1 + 2 + 4 =
7_​ dollars. The maximum amount she can collect is ​_9_ dollars.

## Function Description
Complete the ​_maxMoney_ function in the editor below. It must return an integer that
represents the maximum amount she can collect, modulo ​_1000000007 (10^9 + 7)_. ​

_maxMoney_ has the following parameters:
 _n:_​ an integer that denotes the number of classmates
 _k:_​ an integer that denotes Julia's unlucky number

## Constraints
● 1 ≤ n ≤ 2 × 10^9
● 1 ≤ k ≤ 4 × 10^15

##Input Constraints
The first line contains an integer, ​_n_​ , that denotes the number of classmates.
The second line contains an integer, ​_k_​ , that denotes Julia's unlucky number.

## Sample Input For Custom Testing
### Sample Input 0
2
2

### Sample Output 0
3

###Explanation 0
Julia visits the following sequence of ​_n = 2_​ classmates:
1. Julia collects ​_1_ dollar from classmate ​_1_​ to get ​_sum = 1_. ​
2. Julia collects ​_2_ dollars from classmate ​_2_​ to get ​_sum = 1 + 2 = 3_; ​ observe that she collected a maximal amount of money and avoided having exactly ​_k = 2_ dollars.

## Sample Input For Custom Testing
### Sample Input 1
2
1

### Sample Output 1
2

### Explanation 1
Julia visits the following sequence of ​_n = 2_​ classmates:
1. Julia will not collect ​_1_​ dollar from classmate ​_1_​ because ​_k = 1_​ and she refuses to have a ​_sum ≡ k_​ at any time.
2. Julia moves on and collects ​_2_ dollars from classmate _2_​ to get ​_sum = 0 + 2 = 2_.

## Sample Input For Custom Testing
### Sample Input 2
3
3

### Sample Output 2
5

###Explanation 2
Julia must skip some classmate because collecting from all her classmates will result in a ​_sum ≡ k = 3_ when she collects from the second classmate. There are two ways for her to visit all ​_n = 3_​ classmates:
-- She can collect ​_1_​ dollar from classmate ​_1_ to get ​_sum = 1_. ​ Next, she can refuse to
collect ​_2_ dollars from classmate ​_2_​ to avoid having a ​_sum_ equal to ​_k_ . Next, she
can collect _3_​ dollars from classmate ​_3_​ to get ​_sum = 1 + 3 = 4_ .
-- She can refuse to collect ​_1_​ dollar from classmate ​_1_​ , meaning that ​_sum = 0_. ​ Next,
she can collect ​_2_​ dollars from classmate ​_2_​ to get ​_sum = 0 + 2 = 2_. ​ Next, she can
collect ​_3_​ dollars from classmate ​_3_ to get ​_sum = 2 + 3 = 5_ .
Because we want the maximum amount of money that Julia can collect from her
sequentially-numbered classmates without ever having a ​_sum_​ equal to ​_k_, ​ we return ​_5_​ as
our answer.