class Solution {
public:
    int d[5]={0,1,0,-1,0};
    
      bool check2(int x,int y,vector<vector<int>>& h){
        int n=h.size();
        int m=h[0].size();
        
        bool res=false;
        
        if(x==n-1||y==m-1)
        return true;
        
      int t=h[x][y];
        
        for(int i=0;i<4;i++){
            int dx=x+d[i];
            int dy=y+d[i+1];
            
            if(dx<0||dy<0||dx>=n||dy>=m||h[dx][dy]>h[x][y]||h[dx][dy]==INT_MAX)
                continue;
            else{
                h[x][y]=INT_MAX;
                 res=res||check2(dx,dy,h);
                h[x][y]=t;
            }
           
            
        }
        return res;
    }
    
    bool check1(int x,int y,vector<vector<int>>& h){
        int n=h.size();
        int m=h[0].size();
        
        bool res=false;
        
        if(x==0||y==0)
        return true;
        
        int t=h[x][y];
        
        for(int i=0;i<4;i++){
            int dx=x+d[i];
            int dy=y+d[i+1];
            
            if(dx<0||dy<0||dx>=n||dy>=m||h[dx][dy]>h[x][y]||h[dx][dy]==INT_MAX)
                continue;
            else{
                h[x][y]=INT_MAX;
                 res=res||check1(dx,dy,h);
                h[x][y]=t;
            }
           
            
        }
        return res;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        vector<vector<int>> res;
        
        int n=h.size();
        int m=h[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check1(i,j,h)&&check2(i,j,h))
                    res.push_back({i,j});
            }
        }
        return res;
    }
};