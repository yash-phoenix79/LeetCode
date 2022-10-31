class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
     
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<m;i++){
            int val=mat[0][i];
            for(int j=1;j<n&&i+j<m;j++){
                if(mat[j][i+j]!=val)
                    return false;
            }
        }
        
        for(int i=1;i<n;i++){
            int val=mat[i][0];
            for(int j=1;i+j<n&&j<m;j++){
                if(mat[i+j][j]!=val)
                    return false;
            }
        }
        return true;
    }
};