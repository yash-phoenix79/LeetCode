class Solution {
public:
    
    int res=0;
    
    void check(vector<vector<int>>& mat,vector<int>&vis,int n,int m){
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            bool flag=true;
            for(int j=0;j<m;j++){
                if(mat[i][j]&&!vis[j]){
                    flag=false;
                    break;
                }
            }
            if(flag)cnt++;
        }
        
        res=max(res,cnt);
        
    }
    
    void find(int i,vector<vector<int>>& mat, int num,int n,int m,vector<int>&vis){
        
           if(num==0)
    {
        check(mat,vis,n,m);
        return;
    }
       
        if(i==m)
            return;
        
      
        
        find(i+1,mat,num,n,m,vis);
        
        vis[i]=1;
        find(i+1,mat,num-1,n,m,vis);
        vis[i]=0;
        
        
    }
    
    int maximumRows(vector<vector<int>>& mat, int num) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        vector<int>vis(m,0);
        
        find(0,mat,num,n,m,vis);
        
        return res;
    }
};