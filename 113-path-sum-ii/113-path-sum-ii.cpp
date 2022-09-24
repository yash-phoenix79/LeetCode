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
    vector<vector<int>>res;
    
    void find(TreeNode* root,int tar,int sum,vector<int>path){
        if(!root)
            return;
        path.push_back(root->val);
        sum+=root->val;
        if(tar==sum&&!root->left&&!root->right)
            res.push_back(path);
        find(root->left,tar,sum,path);
        find(root->right,tar,sum,path);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        int sum=0;
        find(root,targetSum,sum,path);
        return res;
        
    }
};