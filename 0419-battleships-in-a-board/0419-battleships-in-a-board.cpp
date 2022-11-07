class Solution {
public:
    
    void dfs(int x,int y,vector<vector<char>>& b){
        int n=b.size(),m=b[0].size();
        b[x][y]='.';
        
        // cout<<x<<" "<<y<<endl;
        
        if(x>0&&b[x-1][y]=='X')dfs(x-1,y,b);
        if(y>0&&b[x][y-1]=='X')dfs(x,y-1,b);
        if(x<n-1&&b[x+1][y]=='X')dfs(x+1,y,b);
        if(y<m-1&&b[x][y+1]=='X')dfs(x,y+1,b);
        
    }
    
    int countBattleships(vector<vector<char>>& b) {
        
        int n=b.size(),m=b[0].size(),res=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]=='X')
                {
                    res++;
                    dfs(i,j,b);
                }
            }
        }
        
        return res;
        
    }
};