/*

Medium

1129

164

Add to List

Share
You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).

 

Example 1:


Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
*/
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
       int n=A.size();
        int m=A[0].size();
        //if first value in any row is 0, then flip the row so that most significant bit becomes set
        for(int i=0;i<n;i++){
            if(A[i][0]==0){
                for(int j=0;j<m;j++){
                    A[i][j]=1-A[i][j];
                }
                    
            }
        }
        //if any column has more 0 than 1, flip the column
        for(int j=0;j<m;j++){
            int cz=0;
            int co=0;
            for(int i=0;i<n;i++){
                if(A[i][j]==1) co++;
                else cz++;
            }
            if(cz>co){
              for(int i=0;i<n;i++){
                A[i][j]=1-A[i][j];
            }  
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int p=0;
            for(int j=m-1;j>=0;j--){
                ans+=A[i][j]*pow(2,p);
                p++;
            }
        }
        return ans;
        
    }
};
