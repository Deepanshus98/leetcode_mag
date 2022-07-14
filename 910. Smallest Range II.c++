/*

Medium

1193

369

Add to List

Share
You are given an integer array nums and an integer k.

For each index i where 0 <= i < nums.length, change nums[i] to be either nums[i] + k or nums[i] - k.

The score of nums is the difference between the maximum and minimum elements in nums.

Return the minimum score of nums after changing the values at each index.

 

Example 1:

Input: nums = [1], k = 0
Output: 0
Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
Example 2:

Input: nums = [0,10], k = 2
Output: 6
Explanation: Change nums to be [2, 8]. The score is max(nums) - min(nums) = 8 - 2 = 6.
*/
class Solution 
{
 public:
    int smallestRangeII(vector<int>& nums, int k) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=nums[n-1]-nums[0];
        for(int i=1;i<n;i++)
        {
            int low=min(nums[0]+k,nums[i]-k);
            int high=max(nums[i-1]+k,nums[n-1]-k);
            ans=min(ans,high-low);
        }
        return ans;
    }
};
