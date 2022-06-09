class Solution {
public:
    int distributeCandies(vector<int>& can) {
        unordered_set<int>s;
        for(int i=0;i<can.size();i++)
            s.insert(can[i]);
        return s.size()<=can.size()/2?s.size():can.size()/2;
    }
};