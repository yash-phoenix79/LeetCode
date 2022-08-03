/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL)
            return NULL;
        
        if(root==p||root==q)
            return root;
        
        TreeNode*lefts=lowestCommonAncestor(root->left,p,q);
        TreeNode*rights=lowestCommonAncestor(root->right,p,q);
        
        if(lefts!=NULL&&rights!=NULL)
            return root;
        
        if(lefts==NULL)
            return rights;
        
        else if(rights==NULL)
            return lefts;
        
        return NULL;
        
    }
};