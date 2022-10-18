class Solution {
public:
    
    int f,s;
    vector<int>pref;
    
    vector<vector<vector<int>>>dp;
    
    int find(int idx,vector<int>& nums,int fir,int sec){
        
        int n=nums.size();
        if(idx>=n)
            return 0;
        int res=INT_MIN;
        
        if(dp[idx][fir][sec]!=-1)
            return dp[idx][fir][sec];
        
        res=max(res,find(idx+1,nums,fir,sec));
        
        if(idx+f<=n&&fir){
            res=max(res,pref[idx+f]-pref[idx]+find(idx+f,nums,!fir,sec));
        }
        
        if(idx+s<=n&&sec)
            res=max(res,pref[idx+s]-pref[idx]+find(idx+s,nums,fir,!sec));
        
        return dp[idx][fir][sec]=res;
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int first, int second) {
        
        int n=nums.size();
        pref=vector<int>(n+1,0);
        pref[0]=0;
        for(int i=1;i<=n;i++)
            pref[i]=pref[i-1]+nums[i-1];
        
        // for(auto x:pref)
        //     cout<<x<<" ";
        
        f=first;
        s=second;
        
        dp=vector<vector<vector<int>>>(n+1,vector<vector<int>>(2,vector<int>(2,-1)));
        
        return find(0,nums,1,1);
        
    }
};