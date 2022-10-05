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
    TreeNode* addOneRow(TreeNode* root, int val, int dep) {
        
        if(dep==1){
            TreeNode* newNode=new TreeNode(val);
            newNode->left=root;
            return newNode;
        }
        
        int cnt=0;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* newNode;
        
        while(!q.empty()){
            cnt++;
            int n=q.size();
            while(n--){
                auto cur=q.front();
                q.pop();
                if(cnt!=dep-1){
                    if(cur->left)q.push(cur->left);
                    if(cur->right)q.push(cur->right);
                }
                else{
                    newNode=new TreeNode(val);
                    newNode->left=cur->left;
                    cur->left=newNode;
                    newNode=new TreeNode(val);
                    newNode->right=cur->right;
                    cur->right=newNode;
                }
            }
        }
        return root;
    }
};