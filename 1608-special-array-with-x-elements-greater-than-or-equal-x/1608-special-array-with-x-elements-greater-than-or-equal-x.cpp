class Solution {
public:
    
    int find(vector<int>& nums,int t){
        
        int cnt=0;
        
        for(auto x:nums)
            if(x>=t)
                cnt++;
        return cnt;
        
    }
    
    int specialArray(vector<int>& nums) {
        
        
        int n=nums.size();
        
        int l=0,r=n;
        
        int m;
        
        while(l<=r){
            m=(l+r)/2;
            if(find(nums,m)>m)
                l=m+1;
            else if(find(nums,m)<m)
                r=m-1;
            else
                return m;
        }
        
        return -1;
        
        
    }
};