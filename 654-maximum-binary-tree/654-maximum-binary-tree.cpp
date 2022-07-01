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
    
    TreeNode* construct(vector<int>& nums,int l,int h){
        if(l>h)
            return NULL;
        if(l==h)
            return new TreeNode(nums[l]);
        
        int idx=max_element(begin(nums)+l,begin(nums)+h+1)-begin(nums);
        
        TreeNode* root=new TreeNode(nums[idx]);
        root->left=construct(nums,l,idx-1);
        root->right=construct(nums,idx+1,h);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int n=nums.size();
        int l=0,h=n-1;
        
        return construct(nums,l,h);
        
    }
};