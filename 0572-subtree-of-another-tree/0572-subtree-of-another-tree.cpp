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
    
    bool check(TreeNode* root,TreeNode* sub,bool flag){
        
        if(!sub||!root){
            
            if(sub||root)return false;
            return true;
        }
        
        if(flag){
        if(root->val!=sub->val)
         return false; 
            
            return check(root->left,sub->left,true)&&check(root->right,sub->right,true);
            
        }
        
        if(root->val==sub->val)
             if(check(root->left,sub->left,true)&&check(root->right,sub->right,true))
                 return true;
        
        if(check(root->left,sub,false)||check(root->right,sub,false))
            return true;
        
        return false;
        
    }
    
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        
        return check(root,sub,false);
        
    }
};