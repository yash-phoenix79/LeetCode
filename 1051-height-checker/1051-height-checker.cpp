class Solution {
public:
    int heightChecker(vector<int>& heights) {
       int n=heights.size();
        vector<int>t=heights;
        sort(begin(heights),end(heights));
        int res=0;
        for(int i=0;i<n;i++){
            if(heights[i]!=t[i])
                res++;
        }
        return res;
    }
};