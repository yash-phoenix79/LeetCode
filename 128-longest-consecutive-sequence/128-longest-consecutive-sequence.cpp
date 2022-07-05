class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(begin(nums),end(nums));
        
        int res=0;
        
        for(auto x:s){
            if(s.find(x-1)==s.end()){
                int cnt=0;
                while(s.find(x)!=s.end())
                {
                    cnt++;
                    x++;
                    
                }
                res=max(res,cnt);
            }
        }
        return res;
    }
};