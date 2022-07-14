/*

Medium

2030

61

Add to List

Share
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

 

Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.
*/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int max_cnt = 0;
        for(int i = 1; i < arr.size() - 1; i++){
            if(arr[i] > arr[i-1] and arr[i] > arr[i+1]){
                //go backward
                int j = i-1, cnt = 3;
                while(j-1 >= 0 and arr[j-1] < arr[j]){
                    cnt++;
                    j--;
                }
                //go forward
                int k = i+1;
                while( k + 1 < arr.size() and arr[k+1] < arr[k]){
                    cnt++;
                    k++;
                }
                max_cnt = max(max_cnt, cnt);
            }
        }
        return max_cnt;
    }
};
