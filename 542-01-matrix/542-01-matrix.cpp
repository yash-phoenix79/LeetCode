class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        if(n==0)
            return mat;
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX - 100000));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                    dist[i][j]=0;
                else {
                    if(i>0)
                        dist[i][j]=min(dist[i][j],1+dist[i-1][j]);
                    if(j>0)
                        dist[i][j]=min(dist[i][j],1+dist[i][j-1]);
                }
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i<n-1)
                    dist[i][j]=min(dist[i][j],1+dist[i+1][j]);
                if(j<m-1)
                    dist[i][j]=min(dist[i][j],1+dist[i][j+1]);
            }
        }
        return dist;
    }
};