class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size(); 
        vector<int>ans(n);
        vector<long>pref(n);
        
        pref[0]=nums[0];
        for(int i=1;i<n;i++)
            pref[i]=pref[i-1]+nums[i];
        
        int l=-1,r=2*k;
        
        for(int i=0;i<n;i++){
            if(i-k<0||i+k>=n)
                ans[i]=-1;
            else{
                if(l==-1){
                      ans[i]=(int)(pref[r++]/(2*k+1));
                    l++;
                }
                  
                else
                    ans[i]=(int)((pref[r++]-pref[l++])/(2*k+1));
            }
        }
        return ans;
    }
};