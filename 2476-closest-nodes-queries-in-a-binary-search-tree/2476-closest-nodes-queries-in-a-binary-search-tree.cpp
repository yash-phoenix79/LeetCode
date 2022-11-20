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
    
    void inorder(TreeNode* root,vector<int>&arr){
        if(!root)
            return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
     
        vector<vector<int>>res(q.size());
        
        vector<int>arr;
        inorder(root,arr);
        
        for(int i=0;i<q.size();i++){
            
            int x=lower_bound(arr.begin(),arr.end(),q[i])-arr.begin();
            
            if(x>=0&&x<arr.size()&&arr[x]==q[i])
                res[i]={q[i],q[i]};
            else if(x==0)
                res[i]={-1,arr[0]};
            else if(x==arr.size())
                res[i]={arr[arr.size()-1],-1};
            else
                res[i]={arr[x-1],arr[x]};
            
            
        }
        return res;
        
    }
};