class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.length();
        stack<char>s;
        s.push('1');
        
        string temp="";
        
        char cnt='2';
        for(int i=0;i<n;i++){
           if(pattern[i]=='I'){
                while(!s.empty()){
                    temp+=s.top();
                    s.pop();
                }
                   
            }
            s.push(cnt);
            cnt++;
        }
        while(!s.empty()){
            temp+=s.top();
                    s.pop();
        }
        
        return temp;
    }
};