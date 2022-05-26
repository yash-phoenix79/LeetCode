class Solution {
public:
    
    bool check(vector<vector<char>>& b,int i,int j,int num){
        
        char c='0'+num;
       int row=i-i%3,col=j-j%3;
        
      for(int x=0;x<9;x++)if(b[x][j]==c)return false;
      for(int y=0;y<9;y++)if(b[i][y]==c)return false;
      for(int x=0;x<3;x++){
          for(int y=0;y<3;y++){
              if(b[x+row][y+col]==c)return false;
          }
      }
        
        
        return true;
    }
    
    bool findSol(int i,int j,vector<vector<char>>& b){
        if(i==9)return true;
        if(j==9){
           return findSol(i+1,0,b);
        }
        
        if(b[i][j]!='.')return findSol(i,j+1,b);
        
        for(int n=1;n<=9;n++){
           
            if(check(b,i,j,n)){
                 b[i][j]='0'+n;
                if(findSol(i,j+1,b)) return true;
                 b[i][j]='.';
            }
           
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& b) {
        findSol(0,0,b);
    }
};