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
    
    void find(TreeNode* root,int mini,int maxi){
        if(!root)return;
       
        mini=min(mini,root->val);
        maxi=max(maxi,root->val);
        
        res=max(res,maxi-mini);
        
        find(root->left,mini,maxi);
        find(root->right,mini,maxi);
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        find(root,root->val,root->val);
        
        return res;
        
    }
};