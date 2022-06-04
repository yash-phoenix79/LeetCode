class Solution {
public:
     vector<vector<string>> ans;
    
    bool check(int y,int x,vector<string>board)
    {
    int n=board.size();
        for(int i=0;i<n;i++){
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
    
    void solve(int i,int n,vector<string>board){
     if(i==n)
     {
         ans.push_back(board);
         return;
     }
        for(int idx=0;idx<n;idx++){
            if(check(idx,i,board)){
                board[i][idx]='Q';
                solve(i+1,n,board);
                board[i][idx]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string>board(n);
        string t(n,'.');
        for(int i=0;i<n;i++){
            board[i]=t;
        }
        solve(0,n,board);
        return ans;
    }
};