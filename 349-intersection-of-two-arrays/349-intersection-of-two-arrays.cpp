class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         vector<int>res;
        
        unordered_set<int>s(begin(nums1),end(nums1));
        
        for(auto x:nums2){
            if(s.count(x)){
                res.push_back(x);
                s.erase(x);
            }
        }
        return res;
    }
};