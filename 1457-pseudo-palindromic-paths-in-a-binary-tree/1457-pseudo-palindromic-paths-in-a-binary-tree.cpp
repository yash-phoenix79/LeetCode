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
    
    void find(TreeNode* root,int cnt){
        // if(!root)
        //     return;
        cnt^=(1<<root->val);
        if(root->left)find(root->left,cnt);
        if(root->right)find(root->right,cnt);
        
        if(!root->left&&!root->right)
            if(__builtin_popcount(cnt)<=1)res++;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        if(!root)
            return res;
        
        if(!root->left&&!root->right)
        return 1;
        int cnt=0;
        find(root,cnt);
        return res;
    }
};