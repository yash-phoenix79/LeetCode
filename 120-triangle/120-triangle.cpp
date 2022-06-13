class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
       vector<int>mini=triangle[n-1];
        for(int i=n-2;i>=0;i--)
            for(int j=0;j<=i;j++)
                mini[j]=triangle[i][j]+min(mini[j],mini[j+1]);
        return mini[0];
    }
};