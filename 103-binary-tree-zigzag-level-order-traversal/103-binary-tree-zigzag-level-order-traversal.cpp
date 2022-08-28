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
            vector<vector<int>>res;
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(!root)
            return res;
        
       queue<TreeNode*>q;
        q.push(root);
        int t=0;
        
        while(!q.empty())
        {
            int n=q.size();
           
            vector<int>temp;
            while(n--){
                auto cur=q.front();
                q.pop();
                temp.push_back(cur->val);
                if(cur->left)
                q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            if(t&1)
              reverse(begin(temp),end(temp));
            res.push_back(temp);
            t++;
        }
        return res;
    }
};