/*

Medium

1630

84

Add to List

Share
You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.

Note that the partition must use every integer in nums, and that the score is not necessarily an integer.

Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.

 

Example 1:

Input: nums = [9,1,2,3,9], k = 3
Output: 20.00000
Explanation: 
The best choice is to partition nums into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned nums into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
Example 2:

Input: nums = [1,2,3,4,5,6,7], k = 4
Output: 20.50000
*/
class Solution {
public:
    vector < vector <double> > dp;
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        dp=vector<vector<double>>(n,vector<double>(K+1,-1));
        return helper(A,0,K);      
    }
    double helper(vector<int>& a,int idx,int k)
    {
        if(idx >= a.size()) return 0;
        if(!k) return INT_MIN;
        if(dp[idx][k]!=-1) return dp[idx][k];
        double ans = INT_MIN;
        double sum = 0;
        for(int i = idx;i<a.size();i++)
        {
            sum = sum+a[i];
            ans = max(sum/(i-idx+1) + helper(a,i+1,k-1),ans);
        }
        return dp[idx][k] = ans;
    }
};
