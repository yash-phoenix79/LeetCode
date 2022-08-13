class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<int>count(32,0);
        long long res=0;
        for(auto x:unordered_set(nums.begin(),nums.end())){
            count[__builtin_popcount(x)]++;
        }
        
        for(int i=1;i<32;i++){
            for(int j=1;j<32;j++){
                if(i+j>=k)
                 res+=(count[i]*count[j]);   
            }
        }
        return res;
    }
};