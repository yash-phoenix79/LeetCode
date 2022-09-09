class Solution {
public:
    
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]!=b[0])
            return a[0]>b[0];
        return a[1]<b[1];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        
        sort(pro.begin(),pro.end(),comp);
        int res=0;
        int maxUntil=INT_MIN;
        for(auto p:pro){
            if(maxUntil>p[1])res++;
            else
                maxUntil=p[1];
        }
        return res;
    }
};