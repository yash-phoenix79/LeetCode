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
    
  bool res=false;
    
    void check(TreeNode* root,int t,int sum){
        if(!root)
            return;
        sum+=root->val;
        if(sum==t&&!root->left&&!root->right){
            res=true;
            return;
        }
        if(res)
            return;
        
        check(root->left,t,sum);
        check(root->right,t,sum);
        
    }
    
    bool hasPathSum(TreeNode* root, int t) {
        if(!root)
            return false;
        int sum=0;
        check(root,t,sum);
        return res;
    }
};