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
    
    int left,right,val;
    
    int findCnt(TreeNode* root){
        if(!root)
            return 0;
        int l=findCnt(root->left);
        int r=findCnt(root->right);
        if(root->val==val){
            left=l;
            right=r;
        }
        return l+r+1;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val=x;
        int cnt=findCnt(root);  
        
        if(max(max(left,right),cnt-left-right-1)>n/2)
            return true;
        return false;
        
    }
};