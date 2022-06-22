class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        set<int>s;
       for(int i:nums){
           
            s.insert(i);
           if(s.size()>3)
               s.erase(s.begin());
       }
          
        return s.size()==3?*(s.begin()):*(s.rbegin());
        
    }
};