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
    int res=INT_MIN;
    
    int find(TreeNode* root){
        if(!root)
            return 0;
        int l=max(find(root->left),0);
        int r=max(find(root->right),0);
        
        res=max(res,root->val+l+r);
        return root->val+max(l,r);
        
    }
    
    int maxPathSum(TreeNode* root) {
     
        if(!root)
            return 0;
        find(root);
        return res;
        
    }
};