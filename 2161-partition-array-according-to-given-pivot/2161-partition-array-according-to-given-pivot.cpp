class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        
        int n=nums.size();
        vector<int>l,r;
        int c=0;
        
        for(auto x:nums){
            if(x<p)
                l.push_back(x);
            else if(x>p)
                r.push_back(x);
            else
                c++;
        }
        
        while(c--)
            l.push_back(p);
        l.insert(l.end(),r.begin(),r.end());
        return l;
        
    }
};