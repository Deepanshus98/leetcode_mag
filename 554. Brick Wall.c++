/*

Medium

1861

104

Add to List

Share
There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.

 

Example 1:


Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
Output: 2
*/
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> mp;
        int n=wall.size();
        for(vector<int> a:wall){
            int k=0;
            for(int i=0;i<a.size()-1;i++){
                k+=a[i];
                ++mp[k];
            }
        }
        int mx=n;
        for(auto it:mp){
            mx=min(mx,n-it.second);
        }
        return mx;
        
        
    }
};
