/*

Medium

745

242

Add to List

Share
You are given the root of a binary tree with n nodes, where each node is uniquely assigned a value from 1 to n. You are also given a sequence of n values voyage, which is the desired pre-order traversal of the binary tree.

Any node in the binary tree can be flipped by swapping its left and right subtrees. For example, flipping node 1 will have the following effect:


Flip the smallest number of nodes so that the pre-order traversal of the tree matches voyage.

Return a list of the values of all flipped nodes. You may return the answer in any order. If it is impossible to flip the nodes in the tree to make the pre-order traversal match voyage, return the list [-1].

 

Example 1:


Input: root = [1,2], voyage = [2,1]
Output: [-1]
Explanation: It is impossible to flip the nodes such that the pre-order traversal matches voyage.
*/
public:
    vector<int>v;
    void preorder(TreeNode* &root,vector<int> &voyage, int &a){
        auto it = find(v.begin(), v.end(), -1);

        if(!root || a>=voyage.size() || it != v.end())
        {
            return;
        }
        int i = a;
        int val  = voyage[i];
        int rov = root->val;
        if(rov!=val){
            v = {-1};
            return;
        }
        else if(root->left && root->left->val !=voyage[i+1]){
            if(root->right && root->right->val == voyage[i+1]){
                v.push_back(rov);
                TreeNode* t = root->left;
                root->left = root->right;
                root->right = t;
            }
            else{
                v = {-1};
                return;
            }
            
        }
        
        
        a++;
        preorder(root->left,voyage,a);
        preorder(root->right,voyage,a);
        
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(root==NULL || root->val!=voyage[0])
            return {-1};
        
        int a =0;
        preorder(root,voyage,a);
        
        return v;
    }
};
