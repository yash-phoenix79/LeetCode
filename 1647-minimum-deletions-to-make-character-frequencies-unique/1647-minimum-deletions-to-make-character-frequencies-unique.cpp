class Solution {
public:
    int minDeletions(string s) {
     
        int n=s.length();
        vector<int>al(26,0);
        for(int i=0;i<n;i++)
            al[s[i]-'a']++;
        
        sort(al.begin(),al.end(),greater<int>());
        int prev=INT_MAX,keep=0;
        
        for(auto x:al){
            if(!x||!prev)break;
            prev=min(x,prev-1);
            keep+=prev;
        }
        return n-keep;
    }
};