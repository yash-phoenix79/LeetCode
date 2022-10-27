class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        
        vector<pair<int,int>>p1,p2;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j])
                    p1.push_back({i,j});
                if(img2[i][j])
                    p2.push_back({i,j});
            }
        }
        
        map<pair<int,int>,int>s;
        int res=0;
        
        for(auto [a1,b1]:p1){
            for(auto [a2,b2]:p2){
                s[{a1-a2,b1-b2}]++;
                res=max(res,s[{a1-a2,b1-b2}]);
            }
        }
        return res;
    }
};