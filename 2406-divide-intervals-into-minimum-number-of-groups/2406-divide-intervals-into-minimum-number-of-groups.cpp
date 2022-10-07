class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        
        vector<vector<int>>res;
        for(int i=0;i<in.size();i++){
            res.push_back({in[i][0],1});
            res.push_back({in[i][1]+1,-1});
        }
        
        sort(begin(res),end(res));
        int ans=0,sum=0;
        
        for(int i=0;i<res.size();i++)
            ans=max(ans,sum+=res[i][1]);
        return ans;
    }
};