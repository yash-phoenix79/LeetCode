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
    
    unordered_map<int,vector<TreeNode*>>m;
    
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if((n&1)==0)return {};
        if(n==1)return {new TreeNode(0)};
        
        if(m[n].size()!=0)
            return m[n];
        
        vector<TreeNode*>res;
        
        for(int i=1;i<n;i+=2){
            
            vector<TreeNode*>l=allPossibleFBT(i);
            vector<TreeNode*>r=allPossibleFBT(n-i-1);
            for(auto x:l){
                for(auto y:r){
                    TreeNode* root=new TreeNode(0);
                    root->left=x;
                    root->right=y;
                    res.push_back({root});
                }
            }
        }
        return m[n]=res;
        
    }
};