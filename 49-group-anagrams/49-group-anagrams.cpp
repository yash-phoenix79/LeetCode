class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     
        int n=strs.size();
        vector<vector<string>>res;
        vector<pair<string,int>>t(n);
            
        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(begin(temp),end(temp));
            t[i]={temp,i};
        }
        
        sort(begin(t),end(t),[](auto &a,auto &b){
            if(a.first==b.first)
                return a.second<b.second;
            return a.first<b.first;
        });
        
        int i=0;
        int j=0;
        while(j<n){
            vector<string>ans;
            while(j<n&&t[j].first==t[i].first){
                ans.push_back(strs[t[j].second]);
                j++;
            }
            res.push_back(ans);
            i=j;
        }
    return res;
    }
};