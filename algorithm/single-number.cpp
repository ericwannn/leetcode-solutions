/* Description
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#include <unordered_map>
#include <vector>

using namespace std;

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] ? m[nums[i]]++ : m[nums[i]] = 1;
        }
        unordered_map<int, int>::const_iterator it;
        for (it = m.begin(); it != m.end(); it++)
        {
            if (it->second == 1)
                return it->first;
        }
        return 0;
    }
};




class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for(auto e : nums)
            val ^= e;

        return val;
    }
};