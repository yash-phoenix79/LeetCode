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
    
    TreeNode* help(int& idx,int l,int r,vector<int>& pr, vector<int>& in){
        if(l>r)
            return NULL;
        int i=l;
        while(pr[idx]!=in[i])
            i++;
        
        idx++;
        TreeNode* root=new TreeNode(in[i]);
        root->left=help(idx,l,i-1,pr,in);
        root->right=help(idx,i+1,r,pr,in);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
        int idx=0;
        int l=0,r=pr.size()-1;
        
        return help(idx,l,r,pr,in);
        
    }
};