class Solution {
public:
    int lengthOfLastWord(string s) {
        
         int i=s.length()-1;
        while(i>=0&&s[i]==' ')
            i--;
        
        s=s.substr(0,i+1);
     
        stringstream x(s);
        string t,t1;
        
       
        
        while(getline(x,t,' ')){
            
            t1=t;
        }
        return t1.length();
        
    }
};