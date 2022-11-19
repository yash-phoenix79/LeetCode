class Solution {
public:
        
        static bool mycomp(pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second;
        }
    
    int minimumOperations(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)
            return 0;
        
        if(n==2){
            if(nums[0]==nums[1])return 1;
            return 0;
        }
        
        unordered_map<int,int>ev,od;
        
        for(int i=0;i<n;i++){
            if(i%2==0)
                ev[nums[i]]++;
            else
                od[nums[i]]++;
        }
        
        vector<pair<int,int>>e,o;
        
        for(auto &i:ev)
            e.push_back(i);
        
        for(auto &i:od)
            o.push_back(i);
        
        sort(begin(e),end(e),mycomp);
        sort(begin(o),end(o),mycomp);
        
        if(e[0].first!=o[0].first)
            return n-e[0].second-o[0].second;
        
        int ef=e[0].second;
        int es=e.size()==1?0:e[1].second;
        int of=o[0].second;
        int os=o.size()==1?0:o[1].second;
        
        return n-max(ef+os,es+of);
        
    }
};