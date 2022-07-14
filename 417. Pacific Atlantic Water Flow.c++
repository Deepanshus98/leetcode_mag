/*
Medium

4104

905

Add to List

Share
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 

Example 1:


Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Example 2:

Input: heights = [[2,1],[1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]
*/
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
    int m=mat.size(),n=mat[0].size();
    vector<vector<bool>>pacific(m, vector<bool>(n,false));
    vector<vector<bool>>atlantic(m, vector<bool>(n,false));
    vector<vector<int>> result;

    for(int i=0;i<n;i++){
        dfs(mat,pacific,0,i,-1); //for pacific top
        dfs(mat,atlantic,m-1,i,-1); //for atlantic bottom
    }

    for(int i=0;i<m;i++){
        dfs(mat,pacific,i,0,-1); //for pacific left
        dfs(mat,atlantic,i,n-1,-1); //for atlantic right
    }

    //cal result
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(pacific[i][j] && atlantic[i][j]){
                result.push_back({i,j});

            }
        }
    }
    return result;
}

void dfs(vector<vector<int>>& mat,vector<vector<bool>>& ocean,int r, int c,int prev){
    if(r<0 || c<0 || r>=mat.size() || c>=mat[0].size() || prev>mat[r][c] || ocean[r][c]==true)
        return;
    ocean[r][c]=true;

    dfs(mat,ocean,r+1,c,mat[r][c]);
    dfs(mat,ocean,r-1,c,mat[r][c]);
    dfs(mat,ocean,r,c+1,mat[r][c]);
    dfs(mat,ocean,r,c-1,mat[r][c]);
}
};
