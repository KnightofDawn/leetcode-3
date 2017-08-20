/*
397. Integer Replacement

Given a positive integer n and you can do operations as follow:




If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.




What is the minimum number of replacements needed for n to become 1?




Example 1:
Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1



Example 2:
Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
*/

int integerReplacement(int n) {
    int k = 0;
    while (n != 1) {
        if (n & 1) {
            if ((n & 3) == 3 && n > 3) {
                n += 1;
            } else {
                n -= 1;
            }
        } else {
            n = (n >> 1) & 0x7fffffff;
        }
        k ++;
    }
    return k;
}


/*
Difficulty:Medium
Total Accepted:21.8K
Total Submissions:72.3K


Companies Google Baidu
Related Topics Math Bit Manipulation

*/
