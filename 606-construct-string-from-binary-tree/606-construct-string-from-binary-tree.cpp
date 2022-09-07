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
    
    string findStr(TreeNode* root,string res){
        if(!root)
            return "";
        string t=to_string(root->val);
        res+=(t);
        
        string l=findStr(root->left,"");
        string r=findStr(root->right,"");
       
        if(r!=""){
            res.append("("+l+")");
            res.append("("+r+")");
        }
        
         else if(l!="")
            res.append("("+l+")");
            
        return res;
        
    }
    
    string tree2str(TreeNode* root) {
        if(!root)
            return "";
       return findStr(root,"");
    }
};