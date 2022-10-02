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
    
    int find(TreeNode* root){
      
        if(!root)
            return INT_MAX/2;
          if(!root->left&&!root->right)
            return 1;
        return 1+min(find(root->left),find(root->right));
    }
    
    int minDepth(TreeNode* root) {
     
        if(!root)
            return 0;
        
        return find(root);
        
    }
};