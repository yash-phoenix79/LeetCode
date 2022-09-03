class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        int l=0,h=m-1;
        int mid;
        
        while(l<=h){
            mid=l+(h-l)/2;
            int idx=0;
            for(int i=0;i<n;i++){
                if(mat[idx][mid]<mat[i][mid])
                  idx=i;
           }
            
            if((mid==0||mat[idx][mid-1]<mat[idx][mid])&&(mid==m-1||mat[idx][mid+1]<mat[idx][mid]))
                return {idx,mid};
            else if(mid>0&&mat[idx][mid-1]>mat[idx][mid])
                h=mid-1;
            else
                l=mid+1;
            
        }
        
        return {-1,-1};
        
    }
};