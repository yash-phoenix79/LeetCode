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
    int mini=INT_MAX;
    
    void minDep(TreeNode* root,int dep){
        if(!root)
            return ;
        
        if(!root->left&&!root->right){
            mini=min(mini,dep);
            return ;
        }
        
       minDep(root->left,dep+1);
       minDep(root->right,dep+1);
        
        
        
    }
    
    int minDepth(TreeNode* root) {
       if(!root)
           return 0;
        
       minDep(root,1);
        return mini;
    }
};