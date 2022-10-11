class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
     
        
        for(int i=1;i<mat.size();i++){
            for(int j=1;j<mat[0].size();j++){
                if(mat[i][j]==0)continue;
                mat[i][j]=1+min({mat[i-1][j],mat[i][j-1],mat[i-1][j-1]});
            }
        }
        
        int res=0;
        for(auto x:mat){
            for(auto y:x)
                res+=y;
        }
        
        return res;
        
    }
};