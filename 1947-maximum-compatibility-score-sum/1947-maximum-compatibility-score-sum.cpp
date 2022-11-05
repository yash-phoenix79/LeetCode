class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& s, vector<vector<int>>& m) {
        
        int res=0;
        vector<int>pos;
        int n=s.size();
        for(int i=0;i<n;i++)
            pos.push_back(i);
        
        do{
            
            int sum=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<s[0].size();j++)
                    sum+=s[pos[i]][j]==m[i][j];
            }
            res=max(res,sum);
            
            
        }while(next_permutation(pos.begin(),pos.end()));
        
        return res;
        
    }
};