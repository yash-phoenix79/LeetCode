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
    
   
    
    void find(TreeNode* root,int k,vector<vector<int>>&res){
        if(!root)
            return;
        if(res.size()<k){
            res.push_back({});
        }
        res[k-1].push_back(root->val);
        find(root->left,k+1,res);
        find(root->right,k+1,res);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>>res;
        if(!root)
            return res;
        
        int k=1;
        find(root,k,res);
        return res;
    }
};