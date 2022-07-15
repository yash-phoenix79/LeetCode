class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        int n=shifts.size();
        vector<long long>shift(n);
        shift[n-1]=shifts[n-1];
        for(int i=n-2;i>=0;i--){
            shift[i]=(long long)shifts[i]+shift[i+1];
        }
            
       for(int i=0;i<s.length();i++){
           int t=s[i]-'a';
           shift[i]%=26;
           t+=shift[i];
           if(t>=26)
               t%=26;
           s[i]='a'+t;
       }
        return s;
    }
};