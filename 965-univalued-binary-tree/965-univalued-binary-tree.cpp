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
   
    
    bool check(TreeNode* root,int valu){
        if(!root)
            return true;
        if(root->val!=valu)
            return false;
        if(!check(root->left,valu)||!check(root->right,valu))
            return false;
        return true;
    }
    
    bool isUnivalTree(TreeNode* root) {
        int valu=root->val;
        return check(root,valu);
    }
};