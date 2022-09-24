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
    
    void find(TreeNode* root,int sum,vector<int>&path){
        if(!root)
            return;
        sum-=root->val;
        path.push_back(root->val);
        if(sum==0&&!root->left&&!root->right)
            res.push_back(path);
        find(root->left,sum,path);
        find(root->right,sum,path);
        sum+=root->val;
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        find(root,targetSum,path);
        return res;
    }
};