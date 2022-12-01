class Solution {
public:
    bool halvesAreAlike(string s) {
     
        int n=s.length();
        string a=s.substr(0,n/2);
        string b=s.substr(n/2);
        
        int cnt1=0,cnt2=0;
        
        for(auto x:a){
            
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='A'||x=='E'||x=='I'||x=='O'||x=='U')
                cnt1++;
            
        }
        
        for(auto x:b){
            
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='A'||x=='E'||x=='I'||x=='O'||x=='U')
                cnt2++;
            
        }
        
        return cnt1==cnt2;
        
    }
};