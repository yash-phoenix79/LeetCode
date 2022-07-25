class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n=mat.size();
        int m=mat[0].size();
        
        int i=0,j=m-1;
        while(j>=0&&i<n){
            if(mat[i][j]==t)
                return true;
            else if(mat[i][j]<t)
                i++;
            else
                j--;
        }
        return false;
    }
};