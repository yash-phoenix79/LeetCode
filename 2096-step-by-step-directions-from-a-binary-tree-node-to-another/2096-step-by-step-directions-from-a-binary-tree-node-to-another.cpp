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
    
    bool findDis(TreeNode* root,int val,string &s){
        if(!root)
            return false;
        
        if(root->val==val)
            return true;
        
        s.push_back('L');
        if(findDis(root->left,val,s))return true;
        s.pop_back();
        
        s.push_back('R');
        if(findDis(root->right,val,s))return true;
        s.pop_back();
        
        return false;
        
    }
    
    TreeNode* findLCA(TreeNode* root,int s,int e){
        if(!root)
            return NULL;
        if(root->val==s||root->val==e)
            return root;
        
        TreeNode* l=findLCA(root->left,s,e);
        TreeNode* r=findLCA(root->right,s,e);
        
        if(l&&r)return root;
        
        return l?l:r;
        
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(!root)
            return "";
        
        TreeNode*lca=findLCA(root,startValue,destValue);
        
        string lca_start="";
        string lca_end="";
        
        findDis(lca,startValue,lca_start);
        findDis(lca,destValue,lca_end);
        
        for(auto &c:lca_start)c='U';
        
        return lca_start+lca_end;
        
    }
};