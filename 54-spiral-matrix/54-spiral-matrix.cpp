class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int row_s=0,row_e=n-1,col_s=0,col_e=m-1;
        
        vector<int>ans;
        while(col_s<=col_e&&row_s<=row_e){
            for(int j=col_s;j<=col_e;j++)
            ans.push_back(matrix[row_s][j]);
        row_s++;
        if(col_s<=col_e&&row_s<=row_e)
        for(int i=row_s;i<=row_e;i++)
            ans.push_back(matrix[i][col_e]);
        col_e--;
         if(col_s<=col_e&&row_s<=row_e)
        for(int j=col_e;j>=col_s;j--)
            ans.push_back(matrix[row_e][j]);
        row_e--;
         if(col_s<=col_e&&row_s<=row_e)
        for(int i=row_e;i>=row_s;i--)
            ans.push_back(matrix[i][col_s]);
        col_s++;
        }
        
        return ans;
    }
};