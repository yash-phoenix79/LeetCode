class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int>s;
        for(auto x:nums)
            s.insert(x);
        
        int i=0;
        int n=s.size();
        auto it=s.begin();
        while(n--){
            nums[i++]=*it;
            it++;
        }
        
        return s.size();
        
    }
};