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
    
    void findSum(TreeNode* root,bool check){
        if(!root)
            return;
        if(!root->left&&!root->right&&check){
            res+=root->val;
            return;
        }
        findSum(root->left,true);
        findSum(root->right,false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        bool check=false;
        findSum(root,check);
        return res;
    }
};