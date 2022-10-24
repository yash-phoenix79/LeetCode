class Solution {
public:
    bool asteroidsDestroyed(int ms, vector<int>& as) {
        
        long long m=ms;
        int n=as.size();
        sort(begin(as),end(as));
        
        for(int i=0;i<n;i++){
            if(as[i]<=m)
                m+=as[i];
            else
                return false;
        }
        return true;
    }
};