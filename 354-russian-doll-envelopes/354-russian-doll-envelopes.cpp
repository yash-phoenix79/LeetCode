class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end(),[](vector<int>&v1,vector<int>&v2){
            if(v1[0]==v2[0])return v1[1]>v2[1];
            return v1[0]<v2[0];
        });
        
        vector<int>res;
        
        for(int i=0;i<e.size();i++){
            int idx=lower_bound(res.begin(),res.end(),e[i][1])-res.begin();
            if(idx==res.size())res.push_back(e[i][1]);
            else res[idx]=e[i][1];
        }
        return res.size();
    }
};