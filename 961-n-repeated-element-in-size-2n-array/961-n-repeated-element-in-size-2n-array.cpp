class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto x:nums){
            m[x]++;
            if(m[x]>1)
                return x;
        }
        return -1;
    }
};