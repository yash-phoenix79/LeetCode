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
    int res=0;
    
    void find(TreeNode* root,vector<int>arr){
        
        arr[root->val]++;
        if(root->left)find(root->left,arr);
        if(root->right)find(root->right,arr);
        
        if(!root->left&&!root->right){
            int cnt=0;
            for(int i=1;i<=9;i++){
                if(arr[i]%2)
                    if(++cnt>1)
                        break;
            }
            if(cnt<=1)
                res++;
        }
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)
            return res;
      
        vector<int>arr(10,0);
        
        find(root,arr);
        return res;
    }
};