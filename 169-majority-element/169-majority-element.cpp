class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        
        int ans=nums[0],cnt=1;
        
        for(int i=1;i<n;i++){
            if(cnt==0){
                ans=nums[i];
                cnt=1;
            }
          else if(nums[i]==ans)
              cnt++;
            else
                cnt--;
        }
        
       return ans;
        
        
    }
};