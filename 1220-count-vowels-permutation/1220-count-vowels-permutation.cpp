class Solution {
public:
    #define N 1000000007
 
   int find(int idx,int n,vector<vector<int>>&dp,vector<vector<int>>&vowels){
       
       if(dp[n][idx]!=-1)
           return dp[n][idx];
       
       int sum=0;
       
   
       for(int j=0;j<vowels[idx].size();j++){
           sum=(sum+find(vowels[idx][j],n-1,dp,vowels))%N;
       } 
        // cout<<sum<<endl;
    
       
       return dp[n][idx]=sum;
   }
    
    int countVowelPermutation(int n) {
   
        vector<vector<int>>vowels(5);
        vowels[0]={1};
        vowels[1]={0,2};
        vowels[2]={0,1,3,4};
        vowels[3]={2,4};
        vowels[4]={0};
        
        vector<vector<int>>dp(n+1,vector<int>(5,-1));
        
        for(int i=0;i<5;i++){
            dp[0][i]=0;
            dp[1][i]=1;
        }
        
        int res=0;
        for(int i=0;i<5;i++)
       res=(res+find(i,n,dp,vowels))%N;
   
        return res;
    }
};