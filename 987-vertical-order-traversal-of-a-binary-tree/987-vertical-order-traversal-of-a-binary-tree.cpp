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
    int mini=0,maxi=0;
    
  
    void findDis(TreeNode* root,int dis){
        if(!root)return;
        mini=min(mini,dis);
        maxi=max(maxi,dis);
        findDis(root->left,dis-1);
        findDis(root->right,dis+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        findDis(root,0);
        res=vector<vector<int>>(maxi-mini+1);
        queue<pair<TreeNode*,int>>q;
        int l=abs(mini);
        q.push({root,l});

        while(!q.empty()){
                  vector<vector<int>>t(maxi-mini+1);
            int n=q.size();
            while(n--){
                auto cur=q.front();
                q.pop();
                TreeNode* node=cur.first;
                int idx=cur.second;
                t[idx].push_back(node->val);
                if(node->left)
                    q.push({node->left,idx-1});
                if(node->right)
                    q.push({node->right,idx+1});
            }
            for(int i=0;i<t.size();i++){
                sort(begin(t[i]),end(t[i]));
                for(auto x:t[i])
                    res[i].push_back(x);
                
            }
           // t.clear();
        }
        return res;
    }
};