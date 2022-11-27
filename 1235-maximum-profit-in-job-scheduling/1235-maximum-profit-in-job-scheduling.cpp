class Solution {
public:
    
    vector<int>dp;
    
    int find(int i,vector<vector<int>>&sch,vector<int>& s){
        int n=s.size();
        if(i>=n)return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int idx=lower_bound(begin(s),end(s),sch[i][1])-begin(s);
        int tak=sch[i][2]+find(idx,sch,s);
        int nTak=find(i+1,sch,s);
        return dp[i]=max(tak,nTak);
        
    }
    
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        
        int n=s.size();
        
        vector<vector<int>>sch(n);
        dp=vector<int>(n,-1);
        
        for(int i=0;i<n;i++)
            sch[i]={s[i],e[i],p[i]};
        
        sort(begin(sch),end(sch));
        sort(begin(s),end(s));
        
        return find(0,sch,s);
        
    }
};