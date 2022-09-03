class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++){
            int maxi=max_element(mat[i].begin(),mat[i].end())-mat[i].begin();
            if((i==0||mat[i-1][maxi]<mat[i][maxi])&&(i==n-1||mat[i+1][maxi]<mat[i][maxi]))
                return {i,maxi};
        }
        return {-1,-1};
    }
};