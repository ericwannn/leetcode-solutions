/** https://leetcode.com/problems/maximum-subarray/description/
 * 
 * 
**/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = nums[0], current = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (current <= 0)
            {
                current = max(current, nums[i]);
                maximum = max(maximum, current);
            }
            else
            {
                current += nums[i];
                maximum = max(maximum, current);

            }
        }
        return maximum;
    }
};