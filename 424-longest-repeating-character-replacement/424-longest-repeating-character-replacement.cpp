class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int start=0;
        int res=0,n=s.length();
        vector<int>cha(26,0);
        
        int maxi=0;
        
        for(int end=0;end<n;end++){
            cha[s[end]-'A']++;
            if(maxi<cha[s[end]-'A'])
                maxi=cha[s[end]-'A'];
            while(end-start-maxi+1>k){
                cha[s[start]-'A']--;
                start++;
            }
            res=max(res,end-start+1);
        }
        return res;
    }
};