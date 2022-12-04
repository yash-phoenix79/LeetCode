class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int n=nums.size();
        
       
        int ans=INT_MAX,idx=-1;
        
        vector<long long>pref(n),suff(n);
        
        pref[0]=nums[0];
        for(int i=1;i<n;i++)
            pref[i]=(long long)pref[i-1]+(long long)nums[i];
        
        suff[n-1]=0;
        for(int i=n-2;i>=0;i--)
            suff[i]=(long long)suff[i+1]+(long long)nums[i+1];
        
        
        int cnt1=1,cnt2=n-1,f,s;
        
        for(int i=0;i<n;i++){
            
            f=pref[i]/cnt1;
            if(cnt2!=0)
            s=suff[i]/cnt2;
            else
                 s=0;
            if(abs(f-s)<ans){
                ans=abs(f-s);
                idx=i;
            }
            
            cnt1++;
            cnt2--;
        }
        return idx;
    }
};