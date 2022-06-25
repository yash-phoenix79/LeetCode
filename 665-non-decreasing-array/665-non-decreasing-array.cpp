class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        if(nums.size()<3)
            return true;
        int cnt1=0,cnt2=0;
        int n=nums.size();
        
        int maxi=INT_MIN,mini=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(nums[i]<maxi)
                cnt1++;
            else
                maxi=nums[i];
        }
        
        for(int i=n-1;i>=0;i--){
            if(nums[i]>mini)
                cnt2++;
            else
              mini=nums[i];  
        }
        return cnt1<2||cnt2<2;
    }
};