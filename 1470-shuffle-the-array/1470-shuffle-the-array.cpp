class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        
        vector<int>res(2*n);
        
        int t=0;
        for(int i=0;i<n;i++){
            res[t++]=nums[i];
            res[t++]=nums[i+n];
        }
        
        return res;
        
    }
};