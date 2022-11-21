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
    
    int find(TreeNode* root,int sum){
        
        if(!root)return 0;
        
        int l=find(root->left,sum);
        int r=find(root->right,sum);
        
        sum+=l+r+root->val;
        
        res+=abs(l-r);
        
        return sum;
    }
    
    int findTilt(TreeNode* root) {
        
         find(root,0);
        return res;
    }
};