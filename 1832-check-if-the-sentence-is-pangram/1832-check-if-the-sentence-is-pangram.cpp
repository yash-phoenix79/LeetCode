class Solution {
public:
    bool checkIfPangram(string s) {
        
        vector<int>al(26,0);
        for(auto x:s)
            al[x-'a']++;
        
        for(auto x:al)
            if(x==0)return false;
        return true;
    }
};