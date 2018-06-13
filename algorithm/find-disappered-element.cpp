/**
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 * Find All Numbers Disappeared in an Array
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), 
 * some elements appear twice and others appear once.
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * Could you do it without extra space and in O(n) runtime? 
 * You may assume the returned list does not count as extra space.
**/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    // Plain solution
    {
        int d;
        for (int i = 0; i < nums.size(); ++i)
        {
            d = abs(nums[i]);
            if (nums[d - 1] > 0) nums[d - 1] = - nums[d - 1];
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }

    vector<int> findDisappearedNumbers2(vector<int>& nums) {
        // Use bitset
        bitset<100000> bsq;
        for(int i = 0; i < nums.size(); ++i)
        {
            int idx = nums[i];
            bsq.set(idx);
        }
        vector<int> res;
        for(int i = 1; i <= nums.size(); ++i)
            if(!bsq.test(i))
                res.emplace_back(i);
        return res;
};  
    