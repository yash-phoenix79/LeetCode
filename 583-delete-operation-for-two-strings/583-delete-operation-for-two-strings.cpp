class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>>seq(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0)
                    seq[i][j]=0;
                else if(word1[i-1]==word2[j-1])
                    seq[i][j]=1+seq[i-1][j-1];
                else
                    seq[i][j]=max(seq[i-1][j],seq[i][j-1]);
            }
        }
        int ans= (m+n)-(2*seq[m][n]);
        return ans;
    }
};