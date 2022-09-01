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
    
    int res=0;
    
    void preOrder(TreeNode* root,int maxval){
        if(!root)
            return;
        if(root->val>maxval)
            maxval=root->val;
        if(root->val==maxval)
            res++;
        preOrder(root->left,maxval);
        preOrder(root->right,maxval);
    }
    
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        preOrder(root,INT_MIN);
        return res;
    }
};