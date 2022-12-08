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
    
    void find(TreeNode* root,vector<int>&t){
        
        if(!root)
            return;
        
        if(!root->left&&!root->right)
            t.push_back(root->val);
        find(root->left,t);
        find(root->right,t);
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
            vector<int>leaf1,leaf2;
        
        find(root1,leaf1);
        find(root2,leaf2);
        
        return leaf1==leaf2;
        
    }
};