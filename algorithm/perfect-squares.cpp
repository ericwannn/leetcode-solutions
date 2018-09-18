/*
279. Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

*/

class Solution {
public:
    int numSquares(int n) 
    {   
        if ( n == 0 ) return 0;
        int a[n + 1] = {0};
        int s, ans;
        for (int i = 1; i <= n; ++i)
        {
            s = sqrt(i);
            if (s * s == i) 
            {
                ans = 1;
            }
            else
            {
                ans = INT_MAX;
                for (int j = 1; j* j < i; ++j)
                {
                    ans = min(ans, a[i - j * j] + 1);
                }
            }
            a[i] = ans;
        }
        //for (int e:a) cout << e << " ";
        return a[n];
    }
};
