/*

Medium

1161

181

Add to List

Share
You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.

 

Example 1:


Input: root = [0,1,2,3,4,3,4]
Output: "dba"
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
