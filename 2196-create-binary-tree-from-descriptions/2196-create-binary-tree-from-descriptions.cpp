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
    
    unordered_map<int,TreeNode*>m;
    unordered_map<int,bool>pari;
    
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        
        for(auto x:des){
            TreeNode* par,*child;
            if(m.find(x[0])!=m.end())
            par=m[x[0]];
            else{
                 par=new TreeNode(x[0]);
                m[x[0]]=par;
            }
               
            
            if(m.find(x[1])!=m.end())
                child=m[x[1]];
            else{
                child=new TreeNode(x[1]);
                m[x[1]]=child;
            }
        
            pari[x[1]]=1;
            if(x[2]==1)
                m[x[0]]->left=m[x[1]];
            else
                m[x[0]]->right=m[x[1]];
            
        }
        TreeNode* root=NULL;
        for(auto x:des){
            if(pari.find(x[0])==pari.end())
            {
                root=m[x[0]];
                break;
            }
        }
        
       return root;
        
    }

};