class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        int m=q.size(),len=nums[0].length();
        
        vector<int>res;
        
        for(int i=0;i<m;i++){
            vector<pair<string,int>>p;
            for(int j=0;j<n;j++)
                p.push_back({nums[j].substr(len-q[i][1]),j});
            sort(p.begin(),p.end());
            res.push_back(p[q[i][0]-1].second);
        }
        return res;
    }
};