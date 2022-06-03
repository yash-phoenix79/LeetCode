class NumArray {
public:
    int n;
    vector<int>pref;
    NumArray(vector<int>& nums) {
        n=nums.size();
        pref=vector<int>(n+1,0);
        for(int i=1;i<=n;i++)
            pref[i]=pref[i-1]+nums[i-1];
            
    }
    
    int sumRange(int left, int right) {
        
        return pref[right+1]-pref[left];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */