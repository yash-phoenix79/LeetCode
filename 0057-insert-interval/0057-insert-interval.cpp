class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        
        vector<vector<int>>res;
        
        int n=in.size();
        int i=0;
        
        while(i<n&&in[i][1]<ni[0]){
            
            res.push_back(in[i++]);
            
        }
        
        while(i<n&&in[i][0]<=ni[1]){
            ni[0]=min(ni[0],in[i][0]);
            ni[1]=max(ni[1],in[i][1]);
            i++;
        }
        res.push_back(ni);
        
        while(i<n){
            res.push_back(in[i++]);
        }
        
        return res;
        
    }
};