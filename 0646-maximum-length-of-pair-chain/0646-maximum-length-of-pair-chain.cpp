class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs),end(pairs),[](auto &a,auto &b){
           return a[1]<b[1]; 
        });
        
        int n=pairs.size(),cnt=0;
        for(int i=0,j=0;j<n;j++)
        {
            if(j==0||pairs[i][1]<pairs[j][0]){
                cnt++;
                i=j;
            }
        }
        return cnt;
    }
};