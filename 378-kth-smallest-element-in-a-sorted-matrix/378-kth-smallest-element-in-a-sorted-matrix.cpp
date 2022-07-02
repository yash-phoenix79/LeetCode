class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
        int n=mat.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        
        for(int i=0;i<n;i++)
            pq.push({mat[i][0],i,0});
        
        int ans;
        
        for(int i=1;i<=k;i++){
            auto cur=pq.top();
            pq.pop();
            int x=cur[1],y=cur[2];
            ans=cur[0];
            if(y+1<n)
                pq.push({mat[x][y+1],x,y+1});
        }
        
        return ans;
        
    }
};