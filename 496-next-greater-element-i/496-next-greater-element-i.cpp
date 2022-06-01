class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size(),-1);
        
        stack<int>s;
        unordered_map<int,int>m;
        
        for(int i=0;i<nums2.size();i++){
            while(!s.empty()&&nums2[i]>s.top()){
                m[s.top()]=nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++){
            if(m.find(nums1[i])!=m.end())
                ans[i]=m[nums1[i]];
        }
        return ans;
    }
};