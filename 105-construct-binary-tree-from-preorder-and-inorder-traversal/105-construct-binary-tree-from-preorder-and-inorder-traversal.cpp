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
    
    TreeNode* help(int& idx,int l,int r,vector<int>& preorder, vector<int>& inorder){
        if(l>r)
            return NULL;
        auto i=find(inorder.begin(),inorder.end(),preorder[idx])-inorder.begin();
        idx++;
        TreeNode* root=new TreeNode(inorder[i]);
        root->left=help(idx,l,i-1,preorder,inorder);
        root->right=help(idx,i+1,r,preorder,inorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     int idx=0;
        int l=0,r=inorder.size()-1;
        return help(idx,l,r,preorder,inorder);
    }
};