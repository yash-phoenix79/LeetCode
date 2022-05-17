class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int t1=-1,t2=-1,cnt1=0,cnt2=0;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            
               if(nums[i]==t1)
                cnt1++;
            else if(nums[i]==t2)
                cnt2++;
            
           else if(cnt1==0){
                t1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
                t2=nums[i];
                cnt2=1;
            }
          
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==t1)
               cnt1++;
            else if(nums[i]==t2)
                cnt2++;
        }
        
        vector<int>ans;
        
        if(cnt1>n/3)
            ans.push_back(t1);
        if(cnt2>n/3)
            ans.push_back(t2);
        
        return ans;
        
    }
};