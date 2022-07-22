class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int t) {
        int res=0,n=mat.size(),m=mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        
        unordered_map<int,int>ma;
        
        for(int colStart=0;colStart<m;colStart++){
            for(int colEnd=colStart;colEnd<m;colEnd++){
                ma={{0,1}};
                int curSum=0;
                for(int row=0;row<n;row++){
                    curSum+= mat[row][colEnd]-(colStart?mat[row][colStart-1]:0);
                    res+=ma[curSum-t];
                    ma[curSum]++;
                }
            }
        }
        return res;
    }
};