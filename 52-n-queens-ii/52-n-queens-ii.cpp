class Solution {
public:
    int res=0;
    
    void solve(int i,int n,vector<int>&col,vector<int>&diag,vector<int>&alt_diag){
        if(i==n){
            res++;
            return;
        }
        for(int y=0;y<n;y++){
            if(!col[y]&&!diag[i+y]&&!alt_diag[i-y+n-1]){
                col[y]=1,diag[i+y]=1,alt_diag[i-y+n-1]=1;
                solve(i+1,n,col,diag,alt_diag);
                col[y]=0,diag[i+y]=0,alt_diag[i-y+n-1]=0;
            }
        }
        return;
    }
    
    int totalNQueens(int n) {
        vector<int>col(n,0),diag(2*n+1,0),alt_diag(2*n+1,0);
        solve(0,n,col,diag,alt_diag);
        return res;
    }
};