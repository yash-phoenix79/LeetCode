class Solution {
public:
    
    vector<int>t;
    
    Solution(vector<int>& nums) {
        t=nums;
    }
    
    vector<int> reset() {
        
        return t;
        
    }
    
    vector<int> shuffle() {
         vector<int>temp=t;
        int n=t.size();
        
        for(int i=n-1;i>=0;i--)
        {
            int idx=rand()%n--;
            swap(temp[idx],temp[i]);
        }
        
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */