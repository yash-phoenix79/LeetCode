class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
     
        int t=0;
        int n=nums.size();
        for(auto x:nums)
            t=t^x;
        
        int b;
        
       for (int i=0; i<32; ++i) {
		if (t & (1<<i)) {
			b = i;
			break;
		}
	}
        
        int r1=0,r2=0;
        
        for(auto x:nums){
            if(x&(1<<b))
                r1^=x;
            else
                r2^=x;
        }
        
        return {r1,r2};
        
    }
};