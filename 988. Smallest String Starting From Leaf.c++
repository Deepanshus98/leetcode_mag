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
    void helper(TreeNode* root, string s, string &ans) {
        if(!root) return;
        
        helper(root -> left, char(root -> val + 97) + s, ans);
        helper(root -> right, char(root -> val + 97) + s, ans);
        
        if(!root -> left && !root -> right) 
            ans = min(ans, char(root -> val + 97) + s);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string ans = "{";
        helper(root, "", ans);
        
        return ans;
    }
};
