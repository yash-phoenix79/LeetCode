class Solution {
public:
     vector<vector<string>> ans;
    
    bool check(int y,int x, vector<string>&board)
    {
    int n=board.size();
        for(int i=0;i<=x;i++){
            if(board[i][y]=='Q')
                return false;
        }
          int i=x,j=y;
        while(i>=0&&j>=0){
            if(board[i--][j--]=='Q')
                return false;
        }
        i=x,j=y;
        while(i>=0&&j<n){
            if(board[i--][j++]=='Q')
                return false;
        }
        return true;
    }   
    
    void solve(int i,int n, vector<string>&board){
     if(i==n)
     {
         vector<string>res;
         for(int x=0;x<n;x++){
             string t="";
             for(int y=0;y<n;y++)
                 t+=board[x][y];
             res.push_back(t);
         }
         ans.push_back(res);
         return;
     }
        for(int idx=0;idx<n;idx++){
            if(check(idx,i,board)){
                board[i][idx]='Q';
                solve(i+1,n,board);
                board[i][idx]='.';
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
    vector<string>board(n,string(n,'.'));
        solve(0,n,board);
        return ans;
    }
};