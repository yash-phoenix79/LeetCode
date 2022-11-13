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
    
    void find(vector<pair<int,int>>t){
        
        sort(begin(t),end(t));
        int n=t.size();
        for(int i=0;i<n;i++){
            if(t[i].second==i)
                continue;
            swap(t[i],t[t[i].second]);
            res++;
            i--;
        }
        
    }
    
    int minimumOperations(TreeNode* root) {
        
        if(!root)return 0;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            vector<pair<int,int>>t;
            while(n--){
                auto cur=q.front();
                q.pop();
                t.push_back({cur->val,t.size()});
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            find(t);
        }
        return res;
    }
};