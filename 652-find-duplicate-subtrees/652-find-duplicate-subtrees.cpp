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
    
    string dfs(TreeNode* root,unordered_map<string,int>&m,vector<TreeNode*>&res){
        if(!root)
            return "";
        string cur=to_string(root->val)+","+dfs(root->left,m,res)+","+dfs(root->right,m,res);
        if(m[cur]++==1)res.push_back(root);
        return cur;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>res;
        unordered_map<string,int>m;
        string t=dfs(root,m,res);
        return res;
    }
};