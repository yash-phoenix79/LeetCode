class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int maxLeft=values[0]+0;
        int maxAns=0;
        for(int i=1;i<n;i++){
            maxAns=max(maxAns,maxLeft+values[i]-i);
            maxLeft=max(maxLeft,values[i]+i);
        }
        return maxAns;
    }
};