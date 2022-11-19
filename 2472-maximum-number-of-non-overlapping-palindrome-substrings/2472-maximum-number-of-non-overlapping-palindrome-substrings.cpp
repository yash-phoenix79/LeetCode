class Solution {
public:
    int maxPalindromes(string s, int k) {
     
        int n=s.length();
        if(k==1)return n;
        vector<pair<int,int>>t;
        
        int idx=0,l,r;
        
        while(idx<n){
            l=idx,r=idx;
            while(l>=0&&r<n&&s[l]==s[r]){
                if(r-l+1>=k){
                     t.push_back({l,r});
                    break;
                }
                l--,r++;
            }
            idx++;
            
        }
        
        idx=1;
        while(idx<n){
            l=idx-1,r=idx;
            while(l>=0&&r<n&&s[l]==s[r]){
                if(r-l+1>=k){
                     t.push_back({l,r});
                    break;
                }
                 l--,r++;
            }
            idx++;
        }
        
        sort(begin(t),end(t),[](auto &a,auto &b){
           return a.second<b.second; 
        });
        
        if(t.size()==0)
            return 0;
        
        int res=1,prev=t[0].second;
        
        int m=t.size();
        
        for(int i=1;i<m;i++){
            if(prev>=t[i].first)
                continue;
            else{
                res++;
                prev=t[i].second;
            }
        }
        return res;
    }
};