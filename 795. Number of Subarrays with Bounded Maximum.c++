/*

Medium

1705

96

Add to List

Share
Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,1,4,3], left = 2, right = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
Example 2:

Input: nums = [2,9,2,5,6], left = 2, right = 8
Output: 7
*/
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0;
        int prev_bigger_than_r = -1;
        int count_prev = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > right) {
                prev_bigger_than_r = i;
                count_prev = 0;
            }
            else if (nums[i] < left) {
                res += count_prev;
            }
            
            else {
                count_prev = i - prev_bigger_than_r;
                res += count_prev;
                
            }
        }
        return res;
    }
};
