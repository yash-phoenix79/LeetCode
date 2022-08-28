class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        
        int n=mat.size(),m=mat[0].size(),res=INT_MIN;
        
        for(int l=0;l<m;l++){
            vector<int>row(n,0);
            for(int r=l;r<m;r++){
                for(int i=0;i<n;i++){
                    row[i]+=mat[i][r];
                }
                
                set<int>s;
                s.insert(0);
                int sum=0;
                for(int i=0;i<n;i++){
                    sum+=row[i];
                    auto it=s.lower_bound(sum-k);
                    if(it!=s.end())res=max(res,sum-*it);
                    s.insert(sum);
                }
                
            }
        }
        return res;
    }
};