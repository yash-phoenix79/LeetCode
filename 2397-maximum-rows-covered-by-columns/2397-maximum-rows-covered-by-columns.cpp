class Solution {
public:
    
    int res=0;
    
    void find(vector<vector<int>>& mat, int col,int n,int m,int idx,vector<int>&vis){
        if(col==0||idx>=m){
            int cnt=0;
            for(int i=0;i<n;i++){
                bool check=true;
                for(int j=0;j<m;j++){
                    if(mat[i][j]&&!vis[j]){
                        check=false;
                        break;
                    }
                }
                if(check)
                    cnt++;
            }
            res=max(res,cnt);
            return;
        }
        
        vis[idx]=1;
        find(mat,col-1,n,m,idx+1,vis);
        vis[idx]=0;
        
        find(mat,col,n,m,idx+1,vis);
        return;
    }
    
    int maximumRows(vector<vector<int>>& mat, int col) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>vis(m,0);
        
        find(mat,col,n,m,0,vis);
        return res;
    }
};