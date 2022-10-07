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
    
    int find(TreeNode* root,int prev){
        if(!root)
            return 0;
        int l=find(root->left,root->val);
        int r=find(root->right,root->val);
        
        // cout<<l<<" "<<r<<endl;
        
        res=max(res,l+r);
        if(root->val==prev)
            return 1+max(l,r);
        return 0;
        
    }
    
    int longestUnivaluePath(TreeNode* root) {
         find(root,-1);
        return res;
    }
};