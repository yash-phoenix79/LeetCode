class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>m1,m2;
        
        int cnt1=0,cnt2=0;
        char s,g;
        
        for(int i=0;i<secret.length();i++){
            s=secret[i];
            g=guess[i];
            if(s==g)
                cnt1++;
            else{
               (m1[g]>0)?m1[g]--,cnt2++:m2[g]++;
               (m2[s]>0)?m2[s]--,cnt2++:m1[s]++;
            }
        }
            
        return to_string(cnt1)+"A"+to_string(cnt2)+"B";
    }
};