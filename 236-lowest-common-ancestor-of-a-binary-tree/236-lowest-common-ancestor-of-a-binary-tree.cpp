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
   TreeNode* findLCA(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root)
            return NULL;
        if(root->val==p->val||root->val==q->val)
            return root;
        TreeNode* l=findLCA(root->left,p,q);
        TreeNode* r=findLCA(root->right,p,q);
        if(l&&r)
            return root;
        if(!l)
            return r;
        return l;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root,p,q);
    }
};