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
    
    bool find(TreeNode* root){
        if(!root)return false;
        bool l=find(root->left);
        bool r=find(root->right);
        
        if(!l)
            root->left=NULL;
        if(!r)
            root->right=NULL;
        
        return ((l||r)||root->val);
        
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        bool res=find(root);
        if(!res)return NULL;
        return root;
    }
};