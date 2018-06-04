/* https://leetcode.com/problems/counting-bits/description/
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

    1. It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
    2. Space complexity should be O(n).
    3. Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

*/

// Simply look at the right most bit:
// If it is 1, then clearly it's the same with the previous number is except the last bit. 
// previous : xxxx0, and this one would be xxxx1. So the count would be 1 greater than the previous one.

// Else, where the current number is abcd0, the count would be the same with the number abcd, 
//which already exists in our result table.

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        for(int i = 1;i <= num;i++) 
            res[i] = i&1?res[i-1]+1:res[i>>1];
        return res;
    }
};

