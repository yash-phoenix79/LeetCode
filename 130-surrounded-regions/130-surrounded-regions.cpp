class Solution {
public:
    int d[5]={1,0,-1,0,1};
    
    void dfs(int x,int y,vector<vector<char>>& board){
         
        int n=board.size();
        int m=board[0].size();
        
        board[x][y]='.';
        for(int i=0;i<4;i++){
            int dx=x+d[i];
            int dy=y+d[i+1];
            if(dx<0||dx>=n||dy<0||dy>=m||board[dx][dy]!='O')
                continue;
            dfs(dx,dy,board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
                dfs(i,0,board);
            if(board[i][m-1]=='O')
                dfs(i,m-1,board);
        }
        
        for(int i=0;i<m;i++){
            if(board[0][i]=='O')
                dfs(0,i,board);
            if(board[n-1][i]=='O')
                dfs(n-1,i,board);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.')
                    board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }
        
    }
};