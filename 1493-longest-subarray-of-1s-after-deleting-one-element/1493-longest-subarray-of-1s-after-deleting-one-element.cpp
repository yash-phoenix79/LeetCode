class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        
        int l=0,r=0,m=0;
  
        int res=0;
        
        if(count(nums.begin(),nums.end(),0)==n)return 0;
        if(count(nums.begin(),nums.end(),1)==n)return n-1;
        
        while(r<n){
            if(nums[r]==0){
                m=r;
                 res=r;
                 r++;
                break;
            }
        
               r++;
        }
        
        while(r<n){
            if(nums[r]==0){
                res=max(res,r-l-1);
              l=m+1;
                m=r;
            }
            r++;
        }
        
        res=max(res,r-l-1);
   

        return res;
        
    }
};