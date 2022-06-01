class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>s;
        vector<int>ans(n,-1);
        
        for(int i=0;i<2*n;i++)
        {
            while(s.size()&&nums[i%n]>nums[s.top()]){
                ans[s.top()%n]=nums[i%n];
                s.pop();
            }
            s.push(i%n);
        }
        return ans;
    }
};