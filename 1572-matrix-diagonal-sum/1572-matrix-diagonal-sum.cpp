class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int res=0;
        
        for(int i=0;i<n;i++){
            res+=mat[i][i];
            if(n-i-1!=i)
                res+=mat[i][n-i-1];
        }
        return res;
    }
};