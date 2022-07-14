/*

Medium

2043

29

Add to List

Share
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
*/
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            
            if (t == NULL) {
                while (!q.empty()) {
                    if (q.front() != NULL)
                        return false;
                    q.pop();
                }
                return true;
            } else {
                q.push(t->left);
                q.push(t->right);
            }
        }
        return true;
    }
};
