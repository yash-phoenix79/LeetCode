class Solution {
public:
   
    int solve(int x,int n,int col,int diag,int alt_diag){
        if(x==n)
            return 1;
         int res=0;
        for(int y=0;y<n;y++){
            
            if(!(col&(1<<y))&&!(diag&(1<<(x+y)))&&!(alt_diag&(1<<(x-y+n-1)))){
               res+=(solve(x+1,n,col|(1<<y),diag|(1<<(x+y)),alt_diag|(1<<(x-y+n-1))));
            }
        }
        return res;
    }
    
    int totalNQueens(int n) {
        int col=0,diag=0,alt_diag=0;
        return solve(0,n,col,diag,alt_diag);
        
    }
};