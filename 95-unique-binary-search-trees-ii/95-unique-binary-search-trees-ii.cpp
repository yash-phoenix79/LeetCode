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
    
    vector<TreeNode*> rec(int l,int r){
        if(l>r)
            return {NULL};
        vector<TreeNode*>res;
        for(int i=l;i<=r;i++){
            vector<TreeNode*>left=rec(l,i-1);
            vector<TreeNode*>right=rec(i+1,r);
            
            for(auto x:left){
                for(auto y:right){
                    TreeNode*root=new TreeNode(i);
                    root->left=x;
                    root->right=y;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return rec(1,n);
    }
};