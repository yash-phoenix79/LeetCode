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
    
    int sumUp(TreeNode* root,long long int sum,int &t){
        if(!root)
            return 0;
        sum+=root->val;
        int find=sumUp(root->left,sum,t)+sumUp(root->right,sum,t);
        if(sum==t)
            return 1+find;
        return find;
    }
    
    int pathSum(TreeNode* root, int t) {
        
        if(!root)
            return 0;
        
        return sumUp(root,0,t)+pathSum(root->left,t)+pathSum(root->right,t);
        
    }
};