class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long res=0;
        int n=nums.size();
        
        vector<int>lmin(n,-1),lmax(n,-1),rmin(n,n),rmax(n,n);
        vector<int>s;
        
        for(int i=0;i<n;i++){
            while(s.size()&&nums[i]<=nums[s.back()])s.pop_back();
            if(s.size())lmin[i]=s.back();
            s.push_back(i);
            
        }
        
        s.clear();
        
        for(int i=n-1;i>=0;i--){
            while(s.size()&&nums[i]<nums[s.back()])s.pop_back();
            if(s.size())rmin[i]=s.back();
            s.push_back(i);
        }
        
        s.clear();
        
        for(int i=0;i<n;i++){
            while(s.size()&&nums[i]>=nums[s.back()])s.pop_back();
            if(s.size())lmax[i]=s.back();
            s.push_back(i);
        }
        
        s.clear();
        
        for(int i=n-1;i>=0;i--){
            while(s.size()&&nums[i]>nums[s.back()])s.pop_back();
            if(s.size())rmax[i]=s.back();
            s.push_back(i);
        }
        
        for(int i=0;i<n;i++){
            long long leftMin=i-lmin[i];
            long long leftMax=i-lmax[i];
            long long rightMin=rmin[i]-i;
            long long rightMax=rmax[i]-i;
            res+=((leftMax*rightMax)-(leftMin*rightMin))*nums[i];
        }
        return res;
    }
};