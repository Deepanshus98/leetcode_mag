/*

Medium

2836

199

Add to List

Share
Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.

 

Example 1:


Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<TreeNode*> allPossibleFBT(int n) {
    if(n==1){
        return {new TreeNode(0)}; //every node it self is a full binary tree
    }
    vector<TreeNode*> temp;
    for(int i=2;i<n;i++) //for every node to be root its should have ood number of node for both left and right side
    {
        vector<TreeNode*>l=allPossibleFBT(i-1);//store left
        vector<TreeNode*>r=allPossibleFBT(n-i);//store right
        for(int j=0;j<l.size();j++)
            {
            for(int k=0;k<r.size();k++)
            {
                TreeNode*root=new TreeNode(0);
                root->left=l[j];
                root->right=r[k];
                temp.push_back(root);
            }
            }
            }
    return temp;
    }
};
