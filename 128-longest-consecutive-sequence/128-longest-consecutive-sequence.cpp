class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(begin(nums),end(nums));
        
        int res=0;
        
        for(auto x:s){
            int cur=1;
            for(int i=1;s.count(x-i);i++)
            {
                s.erase(x-i);
                cur++;
                }
            
            for(int i=1;s.count(x+i);i++)
            {
               s.erase(x+i);
                cur++; 
            }
         
            res=max(res,cur);
        }
        return res;
    }
};