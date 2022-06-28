class Solution {
public:
    int minDeletions(string s) {
        
        int n=s.length();
        vector<int>al(26,0);
        
        for(int i=0;i<n;i++)
            al[s[i]-'a']++;
        
        sort(al.begin(),al.end(),greater<int>());
        
        unordered_map<int,int>m;
        int i=25;
        while(i>=0&&al[i]==0)
            i--;
        
        int res=0;
        while(i>=0){
            if(m[al[i]]==0)
                m[al[i]]++;
            else{
                while(al[i]!=0&&m[al[i]]!=0){
                    res++;
                    al[i]--;
                }
                if(al[i]!=0)
                    m[al[i]]++;
            }
            i--;
        }
        return res;
    }
};