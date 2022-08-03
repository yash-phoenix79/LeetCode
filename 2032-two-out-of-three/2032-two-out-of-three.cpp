class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int>res;
        
         unordered_set<int>s1(begin(nums1),end(nums1));
         unordered_set<int>s2(begin(nums2),end(nums2));
         unordered_set<int>s3(begin(nums3),end(nums3));
        
        unordered_map<int,int>m;
        for(auto x:s1)
            m[x]++;
         for(auto x:s2)
            m[x]++;
         for(auto x:s3)
            m[x]++;
        
        for(auto x:m)
            if(x.second>1)
                res.push_back(x.first);
        return res;
    }
};