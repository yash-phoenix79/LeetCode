class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int n=time.size(),res=0,t;
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++){
            t=time[i]%60;
            if(t==0)
                res+=m[0];
            else
                res+=m[60-t];
            m[t]++;
        }
        
        return res;
        
    }
};