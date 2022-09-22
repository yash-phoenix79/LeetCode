class Solution {
public:
    
    int atmost(vector<int>& nums, int k){
        int res=0,i=0,j;
        int n=nums.size();
        for(j=0;j<n;j++){
            k-=nums[j]%2;
            while(k<0)
                k+=nums[i++]%2;
            res+=j-i+1;
        }
        return res;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};