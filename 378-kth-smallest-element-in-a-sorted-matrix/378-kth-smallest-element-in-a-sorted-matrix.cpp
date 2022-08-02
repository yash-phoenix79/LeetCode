class Solution {
public:
    
    int check(vector<vector<int>>& matrix,int m){
        int cnt=0;
        int n=matrix.size();
        int x=0,y=n-1;
        for(x=0;x<n;x++){
            while(y>=0&&matrix[x][y]>m)y--;
            cnt+=(y+1);
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l=matrix[0][0],r=matrix[n-1][n-1];
        
        int m,res=-1;
        while(l<=r){
            m=(l+r)/2;
            if(check(matrix,m)>=k){
                res=m;
                r=m-1;
            }
            else
                l=m+1;
        }
        
        return res;
        
    }
};