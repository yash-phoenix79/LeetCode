class Solution {
public:
    
   bool dfs(vector<vector<char>>& board, string word,int i,int j,int idx){
       if(idx==word.size())
           return true;
       if(i<0||i>board.size()-1||j<0||j>board[0].size()-1)
           return false;
       if(board[i][j]!=word[idx])
           return false;
       
       board[i][j]='*';
       
       bool ret=dfs(board,word,i+1,j,idx+1)||dfs(board,word,i-1,j,idx+1)||dfs(board,word,i,j+1,idx+1)||dfs(board,word,i,j-1,idx+1);
       
       board[i][j]=word[idx];
       return ret;
       
   }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=size(board),m=size(board[0]);
   
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,word,i,j,0))
                    return true;
                }
            }
        return false;
        
        
    }
};