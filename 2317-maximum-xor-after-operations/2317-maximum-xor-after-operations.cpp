class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res=0,n=nums.size();
        
        for(int i=0;i<n;i++){
            
            int x=nums[i];
            for(int j=31;j>=0;j--){
                if((x>>j)&1)
                    res=res|(1<<j);
            }
            
        }
        
        return res;
        
    }
};