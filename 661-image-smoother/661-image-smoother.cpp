class Solution {
public:
    
    int dx[8]={1,1,1,0,-1,-1,-1,0};
    int dy[8]={1,0,-1,-1,-1,0,1,1};
    
    bool check(int x,int y,int dx,int dy,vector<vector<int>>& img){
        int n=img.size(),m=img[0].size();
        if(x+dx<0||y+dy<0||x+dx>=n||y+dy>=m)
            return false;
        return true;
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m,0));
        int sum=0,cnt=0;;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum=img[i][j],cnt=1;
                for(int k=0;k<8;k++){
                    if(check(i,j,dx[k],dy[k],img))
                    {
                        cnt++;
                        sum+=img[i+dx[k]][j+dy[k]];
                    }
                }
                ans[i][j]=sum/cnt;
            }
        }
        return ans;
    }
};