class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long res=0;
        int n=nums.size();
        
        vector<int>lmini(n,-1),rmini(n,n),lmaxi(n,-1),rmaxi(n,n);
        vector<int>t;
        
        for(int i=0;i<n;i++){
            while(!t.empty()&&nums[i]<=nums[t.back()])t.pop_back();
            if(!t.empty())lmini[i]=t.back();
            t.push_back(i);
        }
        
        t.clear();
        
        for(int i=0;i<n;i++){
            while(!t.empty()&&nums[i]>=nums[t.back()])t.pop_back();
            if(!t.empty())lmaxi[i]=t.back();
            t.push_back(i);
        }
        
        t.clear();
        
        for(int i=n-1;i>=0;i--){
            while(!t.empty()&&nums[i]<nums[t.back()])t.pop_back();
            if(!t.empty())rmini[i]=t.back();
            t.push_back(i);
        }
        
        t.clear();
        
        for(int i=n-1;i>=0;i--){
            while(!t.empty()&&nums[i]>nums[t.back()])t.pop_back();
            if(!t.empty())rmaxi[i]=t.back();
            t.push_back(i);
        }
        
        for(int i=0;i<n;i++){
            long long lmx=i-lmaxi[i];
            long long rmx=rmaxi[i]-i;
            long long lmn=i-lmini[i];
            long long rmn=rmini[i]-i;
            
            res+=(lmx*rmx-lmn*rmn)*nums[i];
            
        }
        return res;
    }
};