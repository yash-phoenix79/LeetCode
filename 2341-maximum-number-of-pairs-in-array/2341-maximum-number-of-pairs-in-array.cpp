class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto x:nums)
            m[x]++;
        
        int fir=0,sec=0;
        for(auto [a,b]:m){
            fir+=b/2;
            sec+=b%2;
        }
        return {fir,sec};
    }
};