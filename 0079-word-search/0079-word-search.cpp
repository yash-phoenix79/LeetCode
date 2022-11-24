class Solution {
public:
    
    bool dfs(int x,int y,vector<vector<char>>& b,string w,int idx){
        
       int n=b.size(),m=b[0].size();
        int len=w.length();
        
        if(idx==len)
            return true;
        
        if(x<0||y<0||x>=n||y>=m)return false;
        if(b[x][y]!=w[idx])return false;
        
        b[x][y]='*';
        bool res=false;
        res=dfs(x+1,y,b,w,idx+1)||dfs(x,y+1,b,w,idx+1)||dfs(x-1,y,b,w,idx+1)||dfs(x,y-1,b,w,idx+1);
        
        b[x][y]=w[idx];
        return res;
    }
    
    bool exist(vector<vector<char>>& b, string w) {
        
        int n=b.size(),m=b[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(i,j,b,w,0))
                    return true;
            }
        }
        return false;
    }
};