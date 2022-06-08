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
    
    int findHeight(TreeNode* root){
        if(!root)
            return 0;
        
        return 1+max(findHeight(root->left),findHeight(root->right));
    }
    
    bool isCompleteTree(TreeNode* root) {
        
        int height=findHeight(root);
        bool t=false;
        queue<TreeNode*>q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            cnt++;
            int n=q.size();
            if(cnt>height)
                break;
            while(n--){
               auto cur=q.front();
                q.pop();
                if(cur==NULL){
                    t=true;
                }
                else{
                    if(t)
                        return false;
                    q.push(cur->left);
                    q.push(cur->right);
                }
           
            }
        }
        return true;
        
    }
};