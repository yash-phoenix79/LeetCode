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
    vector<TreeNode*>res;
    
    void preOrder(TreeNode* root,vector<int>& del){
        if(!root)
            return;
        if(find(del.begin(),del.end(),root->val)!=del.end()){
            if(root->left&&find(del.begin(),del.end(),root->left->val)==del.end())
                res.push_back(root->left);
            if(root->right&&find(del.begin(),del.end(),root->right->val)==del.end())
                res.push_back(root->right);
            if(root->left)
            preOrder(root->left,del);
            if(root->right)
            preOrder(root->right,del);
            root->left=root->right=NULL;
            
        }
        
        preOrder(root->left,del);
        if(root->left&&find(del.begin(),del.end(),root->left->val)!=del.end()){
            
            root->left=NULL;
        }
         preOrder(root->right,del);
        if(root->right&&find(del.begin(),del.end(),root->right->val)!=del.end()){
           
            root->right=NULL;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
        if(find(del.begin(),del.end(),root->val)==del.end())
            res.push_back(root);
        preOrder(root,del);
        return res;
    }
};