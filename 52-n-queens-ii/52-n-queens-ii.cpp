class Solution {
public:
    int res=0;
    
    bool check(int x,int y,vector<vector<bool>>&Queens){
        int n=Queens.size();
        for(int i=0;i<x;i++){
            if(Queens[i][y])
                return false;
        }
        int i=x,j=y;
        while(i>=0&&j>=0){
            if(Queens[i--][j--])
                return false;
        }
        i=x,j=y;
        while(i>=0&&j<n){
            if(Queens[i--][j++])
                return false;
        }
        return true;
    }
    
    void solve(int x,int n,vector<vector<bool>>&Queens){
        if(x==n)
        {
            res++;
            return;
        }
        
        for(int y=0;y<n;y++){
            if(check(x,y,Queens)){
                Queens[x][y]=1;
                solve(x+1,n,Queens);
                Queens[x][y]=0;
            }
        }
        return;
    }
    
    int totalNQueens(int n) {
        
        vector<vector<bool>>Queens(n,vector<bool>(n,0));
        solve(0,n,Queens);
        return res;
        
    }
};