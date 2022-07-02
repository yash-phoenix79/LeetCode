class Solution {
public:
    
    int isElementlessthan(int cur,vector<vector<int>>& mat)
    {
        int n=mat.size();
        int x=0,y=n-1;
        
        int cnt=0;
         for(x=0;x<n;x++){
             while(y>=0&&mat[x][y]>cur)y--;
             cnt+=(y+1);
         }
        
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
        int n=mat.size();
        int l=mat[0][0],h=mat[n-1][n-1];
        
        int res=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(isElementlessthan(m,mat)>=k)
            {
                res=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        
        return res;
        
    }
};