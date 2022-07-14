/*

Medium

3881

302

Add to List

Share
You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.

 

Example 1:


Input: nums = [3,2,1,6,0,5]
Output: [6,3,5,null,2,0,null,null,1]
Explanation: The recursive calls are as follow:
- The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right suffix is [0,5].
    - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix is [2,1].
        - Empty array, so no child.
        - The largest value in [2,1] is 2. Left prefix is [] and right suffix is [1].
            - Empty array, so no child.
            - Only one element, so child is a node with value 1.
    - The largest value in [0,5] is 5. Left prefix is [0] and right suffix is [].
        - Only one element, so child is a node with value 0.
        - Empty array, so no child
*/
class Solution {
public:
    TreeNode* helper(vector<int> nums, int l, int r){
        if(l>r)
            return NULL;
        int maxi = l;
        for(int i=l; i<=r; i++){
            if(nums[i]>nums[maxi]){
                maxi  = i;
            }
        }
        TreeNode* temp = new TreeNode(nums[maxi]);
        temp->left = helper(nums, l, maxi-1);
        temp->right = helper(nums, maxi+1, r);
        return temp;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int maxi =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>nums[maxi])
                maxi = i;
        }
        TreeNode* temp = new TreeNode(nums[maxi]);
        temp->left = helper(nums, 0, maxi-1);
        temp->right = helper(nums, maxi+1, nums.size()-1);
        return temp;
    }
};
