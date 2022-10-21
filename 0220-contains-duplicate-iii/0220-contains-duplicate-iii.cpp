class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int idx, int val) {
        
        int n=nums.size();
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++){
            
            int buc=nums[i]/(long)(val+1);
            if(nums[i]<0)
                buc--;
            
            if(m.find(buc)!=m.end())
                return true;
            else{
                m[buc]=nums[i];
                if(m.find(buc-1)!=m.end()&&nums[i]-m[buc-1]<=val)return true;
                if(m.find(buc+1)!=m.end()&&m[buc+1]-nums[i]<=val)return true;
                
                if(m.size()>idx){
                    int eras=nums[i-idx]/(long)(val+1);
                    if(nums[i-idx]<0)
                        eras--;
                    m.erase(eras);
                }
                
            }
            
        }
        return false;
    }
};