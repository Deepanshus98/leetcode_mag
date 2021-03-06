/*

Medium

1242

63

Add to List

Share
Given an integer array nums, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.

Test cases are generated such that partitioning exists.

 

Example 1:

Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
Example 2:

Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
*/
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int max_1, curr, ans = 1;
        max_1 = curr = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] < max_1){
                max_1 = curr;
                ans = i + 1;
            }
            else if(nums[i] > curr){
                curr = nums[i];                
            }
        }
        return ans;
    }
};
