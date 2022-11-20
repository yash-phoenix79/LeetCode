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
    
    vector<int>arr;
    
    void inorder(TreeNode* root){
        
        if(!root)
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
        
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        
        vector<vector<int>>res;
        
        inorder(root);
        
        for(int i=0;i<q.size();i++){
            int x=lower_bound(begin(arr),end(arr),q[i])-begin(arr);
            int y=upper_bound(begin(arr),end(arr),q[i])-begin(arr);
            
            if(x<arr.size()&&x>=0&&arr[x]==q[i])
                res.push_back({q[i],q[i]});
            else if(x==0)
                res.push_back({-1,arr[x]});
            else if(x==arr.size())
                res.push_back({arr[x-1],-1});
            else if(arr[x]>q[i])
                res.push_back({arr[x-1],arr[y]});
            else
                res.push_back({arr[x],arr[y]});
            
        }
        return res;
    }
};