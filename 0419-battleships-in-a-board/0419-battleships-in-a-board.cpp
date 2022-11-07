class Solution {
public:
    int countBattleships(vector<vector<char>>& b) {
        
        int n=b.size();
        int m=b[0].size();
        
        int res=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(b[i][j]=='X'){
                    
                    if(i-1>=0&&b[i-1][j]=='X')continue;
                    if(j-1>=0&&b[i][j-1]=='X')continue;
                    res++;
                }
                
            }
        }
        
        return res;
        
    }
};