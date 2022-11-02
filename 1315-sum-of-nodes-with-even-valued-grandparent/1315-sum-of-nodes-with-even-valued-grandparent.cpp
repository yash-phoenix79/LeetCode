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
    
    void find(TreeNode* root,int dep,int par,int gra){
        
        if(!root)
            return;
        
        int c=root->val;
        
        if(gra%2==0)
            res+=c;
        
        if(root->left){
               find(root->left,dep+1,root->val,par);
           }
        
        if(root->right){
            find(root->right,dep+1,root->val,par);
         }
        
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        
        find(root,0,-1,-1);
        return res;
    }
};