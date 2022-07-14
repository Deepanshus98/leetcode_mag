/*
Medium

640

905

Add to List

Share
You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Return the number of boomerangs.

 

Example 1:

Input: points = [[0,0],[1,0],[2,0]]
Output: 2
Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].
Example 2:

Input: points = [[1,1],[2,2],[3,3]]
Output: 2
*/
class Solution {
public:
    int distance(vector<int> &x,vector<int> &y)
{
    return (x[0]-y[0])*(x[0]-y[0])+(x[1]-y[1])*(x[1]-y[1]);
}
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int n=points.size();
        unordered_map<int,int> mp;

        int count=0;
        for(int i=0;i<n;i++)
        {

            for(int j=0;j<n;j++)
            {
                if(j==i)
                    continue;
                int d=distance(points[i],points[j]);

                if(mp.find(d)!=mp.end())
                    count+=mp[d]*2;

                mp[d]++;
            }
            mp.clear();
        }

        return count;

    }
};
