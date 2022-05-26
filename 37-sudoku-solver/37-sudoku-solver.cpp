class Solution {
public:
    
    bool check(vector<vector<char>>& b,int i,int j,char c){
       int  t1=i-i%3,t2=j-j%3;
        
        for(int x=0;x<9;x++)if(b[x][j]==c)return false;
        for(int y=0;y<9;y++)if(b[i][y]==c)return false;
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                if(b[t1+x][t2+y]==c)return false;
            }
        }
        return true;
    }
    
    
    bool findSol(int x,int y,vector<vector<char>>& b){
        if(x==9)
            return true;
        if(y==9){
            return findSol(x+1,0,b);
        }
        if(b[x][y]!='.')return findSol(x,y+1,b);
        
        for(char c='1';c<='9';c++){
            if(check(b,x,y,c)){
                b[x][y]=c;
                if(findSol(x,y+1,b))return true; 
                b[x][y]='.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& b) {
        findSol(0,0,b);
    }
};