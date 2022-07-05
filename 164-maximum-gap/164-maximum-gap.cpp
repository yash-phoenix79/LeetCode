class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n=nums.size();
        if(n<2)
            return 0;
        
        int cur=-1,res=0;
        
        set<int>s(begin(nums),end(nums));
        
        for(auto x:s){
            if(cur!=-1&&x!=cur)
                res=max(res,x-cur);
            cur=x;
        }
        
        return res;
        
    }
};