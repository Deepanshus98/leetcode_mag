/*

Medium

3429

308

Add to List

Share
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

 

Example 1:


Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
*/
class Solution {
public:
    vector<TreeNode*> ans;
    string dfs(TreeNode* node, unordered_map<string, bool>& m){
        if(node == nullptr){
            return "#";
        }
        string s = "";
        s += dfs(node->left, m);
        s += dfs(node->right, m);
        s += to_string(node->val) + "#";
        if(m.count(s)){
            if(!m[s]){
                m[s] = true;
                ans.push_back(node);    
            }
        } else{
            m[s] = false;
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, bool> m;
        dfs(root, m);
        return ans;
    }
};
