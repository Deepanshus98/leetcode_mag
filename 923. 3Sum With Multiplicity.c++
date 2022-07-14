/*

Medium

2289

273

Add to List

Share
Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

As the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
*/
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                ans += mp[target-arr[i]-arr[j]];
            }
            ans =ans%1000000007;
            mp[arr[i]]++;
        }
        return ans%1000000007;
    }
};
