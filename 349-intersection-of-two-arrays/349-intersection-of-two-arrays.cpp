class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         vector<int> res;
        unordered_set<int>s1,s2;
        
        for(int i=0;i<nums1.size();i++){
             s1.insert(nums1[i]);
        }
           
        
        
        for(int i=0;i<nums2.size();i++){
            s2.insert(nums2[i]);
        }
         
      
        for(auto x:s1){
            if(find(begin(s2),end(s2),x)!=end(s2))
                res.push_back(x);
        }
      return res;
        
    }
};