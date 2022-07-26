class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int n=nums.size(),res;
        int cnt1=0,cnt2=n;
        
        int ans=INT_MAX;
        
       long long int lSum=0,rSum=0;
        for(int i=0;i<n;i++)
            rSum+=nums[i];
        
        for(int i=0;i<n-1;i++){
            cnt2--;
            rSum-=nums[i];
            cnt1++;
            lSum+=nums[i];
            
            if(abs((lSum/cnt1)-(rSum/cnt2))<ans){
                res=i;
                ans=abs((lSum/cnt1)-(rSum/cnt2));
            }
            
        }
        
        lSum+=nums[n-1];
        cnt1=n;
        
        if(lSum/cnt1<ans){
            res=n-1;
        }
        
        return res;
    }
};