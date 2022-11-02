class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        int n=pref.size();
        int t=pref[0];
        vector<int>res(n);
        res[0]=pref[0];
        
        for(int i=1;i<n;i++){
            int x=pref[i]^t;
            res[i]=x;
            t^=x;
        }
        return res;
    }
};