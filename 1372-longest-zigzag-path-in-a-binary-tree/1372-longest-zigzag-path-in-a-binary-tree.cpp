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
    
    void findDis(TreeNode* root,bool dir,int dis){
        if(!root)
            return;
        res=max(res,dis);
        if(dir){
            findDis(root->right,false,dis+1);
            findDis(root->left,true,1);
        }
        else{
            findDis(root->left,true,dis+1);
            findDis(root->right,false,1);
        }
    }
    
    
    int longestZigZag(TreeNode* root) {
        findDis(root->left,true,1);
        findDis(root->right,false,1);
        return res;
    }
};