class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
     
       vector<int>res;
        vector<pair<int,vector<int>>>t;
        
     for(int i=0;i<nums.size();i++){
         for(int j=0;j<nums[i].size();j++){
             t.push_back({nums[i][j],{i,j}});
         }
     }
        
        sort(begin(t),end(t),[](auto &a,auto &b){
           if(a.second[0]+a.second[1]==b.second[0]+b.second[1])
               return a.second[0]>b.second[0];
            return a.second[0]+a.second[1]<b.second[0]+b.second[1];
        });
        
        for(int i=0;i<t.size();i++)
            res.push_back(t[i].first);
        return res;
        
    }
};