/*

Medium

2151

281

Add to List

Share
Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        if(n<2)
            return false;
        int sum =0;
        int rem =0;
        for(int i =0 ; i<n;i++) {
            sum +=nums[i];
            rem = sum%k;
            if(rem == 0 && i>0) // method 2 for handling 0 index.
                return true;
            // if same reminder exists nums[i] - nums[j] divide by 6.
            // (sum2- sum1)%k =0 then sum2%k = sum1%k.
            if(mp.find(rem) != mp.end()) {
                // check index should be atleast 2 element.
                if(i - mp[rem] >1){
                    return true;
                }
            } else   
               mp[rem] = i;
        }
        return false;
    }
};
