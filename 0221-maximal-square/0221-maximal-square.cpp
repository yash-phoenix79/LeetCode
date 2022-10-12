class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        
        int n=mat.size(),m=mat[0].size();
        
        vector<vector<int>>t(n,vector<int>(m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1')
                    t[i][j]=1;
                else
                    t[i][j]=0;
            }
        }
        
        int res=0;
        for(int i=0;i<n;i++){
            if(t[i][0]){
                res=1;
                break;
            }
        }
        
        for(int i=0;i<m;i++){
            if(t[0][i]){
                res=1;
                break;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(t[i][j]==0)continue;
                else{
                    t[i][j]=1+min({t[i-1][j-1],t[i-1][j],t[i][j-1]});
                    res=max(res,t[i][j]);
                }
            }
        }
        return res*res;
    }
};