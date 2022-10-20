class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
     
        int n=nums.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
            string temp=to_string(nums[i]);
            reverse(begin(temp),end(temp));
            
            s.insert(stoi(temp));
        }
            return s.size();
        
    }
};