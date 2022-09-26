class Solution {
public:
    string smallestNumber(string pat) {
        string res="";
        int n=pat.length();
        stack<char>s;
        s.push('1');
        
        int cnt=2;
        
        for(int i=0;i<n;i++){

            if(pat[i]=='I'){
                while(!s.empty()){
                    res+=s.top();
                    s.pop();
                }
            }
           s.push('0'+cnt++);
            
        }
        
        while(!s.empty()){
                    res+=s.top();
                    s.pop();
                }
        
        return res;
        
    }
};