class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res=0;
        int n=nums.size();
        
        int prev=nums[n-1];
        for(int i=n-2;i>=0;i--){
          int k=nums[i]/prev;
            if(nums[i]%prev!=0){
                k++;
                prev=nums[i]/k;
            }
            res+=(k-1);
        }
return res;        
    }
};