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
    int maxLevelSum(TreeNode* root) {
        long long sum=0;
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        int maxi=INT_MIN;
        int res=1;
        
        while(!q.empty()){
            int n=q.size();
            sum=0;
            while(n--){
                auto cur=q.front();
                q.pop();
                sum+=(cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            if(sum>maxi){
                maxi=sum;
                res=level;
            }
            level++;
        }
        return res;
    }
};