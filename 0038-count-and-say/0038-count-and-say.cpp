class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1)
            return "1";
        string res="";
        
        string t="1";
        
        for(int i=1;i<n;i++){
            
            res="";
            int j=0,len=t.length();
            while(j<len){
                int cnt=0,val=t[j];
                while(j<len&&t[j]==val){
                    cnt++;
                    j++;
                }
                res+=to_string(cnt);
                res+=val;
            }
            t=res;
            
        }
        return t;
    }
};