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
    
    unordered_map<TreeNode*,int>dp;
    int rob(TreeNode* root) {
        if(!root)return 0;
        if(dp.count(root)!=0)
            return dp[root];
        int d=rob(root->left)+rob(root->right);
        int t=root->val;
        if(root->left)
            t+=rob(root->left->left)+rob(root->left->right);
        if(root->right)
            t+=rob(root->right->left)+rob(root->right->right);
        return dp[root]=max(d,t);
    }
};