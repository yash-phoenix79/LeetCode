class Solution {
public:
    
    int res=0;
    
    void find(vector<int>arr,unordered_map<int,int>m){
        
        vector<int>t=arr;
        sort(begin(t),end(t));
        int n=arr.size();
        int i=0;
        while(i<n){
            
            if(arr[i]!=t[i]){
                int x=m[arr[i]];
                int y=m[t[i]];
                int cur=arr[i];
                swap(arr[m[arr[i]]],arr[m[t[i]]]);
               m[cur]=y;
                m[arr[i]]=i;
                res++;
            }
            i++;
        }
    
    }
    
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            vector<int>t;
            unordered_map<int,int>m;
            int n=q.size();
            while(n--){
                auto cur=q.front();
                q.pop();
                m[cur->val]=t.size();
                t.push_back(cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
                
            }
            find(t,m);
            
        }
        return res;
    }
};