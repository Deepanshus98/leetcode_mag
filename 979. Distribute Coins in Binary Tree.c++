/*

Medium

3909

131

Add to List

Share
You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.

 

Example 1:


Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
*/
class Solution {
public:
    
    // calculate required moves in postorder manner
    int traverse(TreeNode* root, int &moves)
    {
        if(!root) return 0;
        int left = traverse(root->left,moves);
        int right = traverse(root->right,moves);
        moves += abs(left) + abs(right);
        return root->val + left + right -1;
    }
    
    int distributeCoins(TreeNode* root) {
        
        int moves = 0;
        traverse(root,moves);
        return moves;
    }
};
