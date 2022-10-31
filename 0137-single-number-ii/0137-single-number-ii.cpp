class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int sz=nums.size();
        int i,j,n;
        
        vector<int>t(32,0);
        
        for(i=0;i<sz;i++){
            n=nums[i];
            for(j=31;j>=0;j--){
                t[j]+=n&1;
                n=n>>1;
                if(!n)
                    break;
            }
        }
        
        int res=0;
        
        for(j=31;j>=0;j--){
            if(t[j]%3)
                res+=(1<<(31-j));
        }
        
        return res;
        
    }
};