class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int t) {
        
        int res=0,n=size(mat),m=size(mat[0]);
        
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        
        for(int colStart=0;colStart<m;colStart++){
            for(int colEnd=colStart;colEnd<m;colEnd++){
                for(int rowStart=0;rowStart<n;rowStart++){
                    int sum=0;
                    for(int rowEnd=rowStart;rowEnd<n;rowEnd++){
                        sum+=mat[rowEnd][colEnd]-(colStart?mat[rowEnd][colStart-1]:0);
                         if(sum==t)
                        res++;
                    }
                   
                }
            }
        }
        return res;
    }
};