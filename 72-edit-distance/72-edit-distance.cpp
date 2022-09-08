class Solution {
public:
    
    // this problem is similar to the approach of Longest Common Subsequence 
    
    int minDistance(string word1, string word2) {
     
        int n=word1.size();//length of first string
        int m=word2.size();//length of second string 
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));//declaring a 2D vector 
        for(int i=1;i<=n;i++)// if a string is not null but the other string is null,then we have no chance but to remove all the elements of the string
            dp[i][0]=i;
        for(int j=1;j<=m;j++)// if a string is not null but the other string is null,then we have no chance but to remove all the elements of the string
            dp[0][j]=j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])//if a letter in word1 is equal to a letter in word2
                    dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }
        return dp[n][m];
    }
};