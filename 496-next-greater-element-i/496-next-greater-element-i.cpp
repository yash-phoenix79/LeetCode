class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        
        stack<int>s;
        
        unordered_map<int,int>m;
        
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty()&&s.top()<nums2[i]){
                s.pop();
            }
            if(s.empty())
                m[nums2[i]]=-1;
           else
                m[nums2[i]]=s.top();
            s.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++)
            ans[i]=(m[nums1[i]]);
        return ans;
    }
};