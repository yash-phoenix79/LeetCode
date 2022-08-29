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
    
    vector<TreeNode*>recur(int l,int r){
        if(l>r)
            return {NULL};
        vector<TreeNode*>res;
        for(int root=l;root<=r;root++){
            vector<TreeNode*>left=recur(l,root-1);
            vector<TreeNode*>right=recur(root+1,r);
            for(auto x:left){
                for(auto y:right){
                    TreeNode* r=new TreeNode(root);
                    r->left=x;
                    r->right=y;
                    res.push_back(r);
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
       return recur(1,n); 
        
    }
};