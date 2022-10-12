class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        
        if(mat.empty())
            return 0;
     
        int n=mat.size(),m=mat[0].size();
        
        vector<int>pre(m),cur(m);
        int res=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!i||!j||mat[i][j]=='0')
                    cur[j]=mat[i][j]-'0';
                else{
                    cur[j]=1+min({pre[j],pre[j-1],cur[j-1]});
                }
                res=max(res,cur[j]);
            }
            fill(pre.begin(),pre.end(),0);
            swap(pre,cur);
        }
        return res*res;
    }
};