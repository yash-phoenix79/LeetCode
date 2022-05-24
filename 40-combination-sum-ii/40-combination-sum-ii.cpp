class Solution {
public:
    void findComb(vector<int>& can, int tar,int idx,vector<int>ds,vector<vector<int>>&ans){
        if(tar==0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx;i<can.size();i++){
            if(i!=idx&&can[i]==can[i-1])continue;
            if(can[i]>tar)continue;
            ds.push_back(can[i]);
            findComb(can,tar-can[i],i+1,ds,ans);
            ds.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
         vector<vector<int>> ans;
        vector<int>ds;
        sort(can.begin(),can.end());
        findComb(can,tar,0,ds,ans);
        return ans;
        
    }
};