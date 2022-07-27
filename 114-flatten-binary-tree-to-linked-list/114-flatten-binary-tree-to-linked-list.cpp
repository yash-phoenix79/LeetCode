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
    
     TreeNode* dum=new TreeNode(-1);
    TreeNode* temp;
    
    void preorder(TreeNode* root){
        if(!root)
            return;
        temp->right=new TreeNode(root->val);
        temp=temp->right;
        preorder(root->left);
        preorder(root->right);
    }
    
    void flatten(TreeNode* root) {
        
        if(!root)
            return;
        
       temp=dum;
        
        preorder(root);
        
        root->right=dum->right;
        root->left=NULL;
     root->right=root->right->right;
;
        
    }
};