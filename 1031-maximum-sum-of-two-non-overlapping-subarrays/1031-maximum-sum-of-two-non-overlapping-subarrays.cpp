class Solution {
public:
    
    int find(vector<int>&nums,int f,int s){
        int n=nums.size();
        
        vector<int>dp1(n,0),dp2(n,0);
        
        int sum=0;
        
        for(int i=0;i<n;i++){
            if(i<f)
            {
                sum+=nums[i];
                dp1[i]=sum;
            }
            else
            {
                sum=sum+nums[i]-nums[i-f];
                dp1[i]=max(dp1[i-1],sum);
            }
        }
        
        sum=0;
        
        for(int i=n-1;i>=0;i--){
            if(i+s>n-1){
                sum+=nums[i];
                dp2[i]=sum;
            }
            else{
                sum=sum+nums[i]-nums[i+s];
                dp2[i]=max(dp2[i+1],sum);
            }
        }
        
        int res=0;
        for(int i=f-1;i+s<n;i++)
            res=max(res,dp1[i]+dp2[i+1]);
        
        return res;
        
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        return max(find(nums,firstLen,secondLen),find(nums,secondLen,firstLen));
        
    }
};