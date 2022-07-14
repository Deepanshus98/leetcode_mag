/*

Medium

4103

395

Add to List

Share
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
*/
class Solution {
public:
    int memo(int i, int p, int q, vector<string> &arr, vector<vector<vector<int>>> &dp){
        int c0=0, c1=0;
        for(char &c:arr[i])
            if(c=='0') c0++; else c1++;
        
        if(i==0){
            if(c0<=p && c1<=q) return 1;
            else return 0;
        }
        
        if(dp[i][p][q]!=-1) return dp[i][p][q];
        
        int nottake=memo(i-1, p, q, arr, dp);
        int take=0;
        if(c0<=p && c1<=q) take=1+memo(i-1, p-c0, q-c1, arr, dp);
        
        return dp[i][p][q]=max(take, nottake);
    }
    int findMaxForm(vector<string>& arr, int p, int q) {
        int n=arr.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(p+1, vector<int>(q+1, -1)));
        return memo(n-1, p, q, arr, dp);
    }
};
