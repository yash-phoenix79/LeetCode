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
    
    void inorder(TreeNode* root,unordered_map<int,int>&m){
        if(!root)return;
        inorder(root->left,m);
        m[root->val]++;
        inorder(root->right,m);
    }
    
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>m;
        
        inorder(root,m);
        
        int t=0;
        
        for(auto x:m)
            t=max(t,x.second);
        
        vector<int>res;
        for(auto x:m){
            if(x.second==t)
                res.push_back(x.first);
        }
        return res;
    }
};