class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n=num.length();
        if(n<=k)
            return "0";
        
        stack<char>s;
        s.push(num[0]);
        
        for(int i=1;i<n;i++){
            
            while(k>0&&!s.empty()&&s.top()>num[i]){
                s.pop();
                k--;
            }
            
            s.push(num[i]);
            
            if(s.size()==1&&num[i]=='0')
                s.pop();
            
        }
        
        while(k&&!s.empty()){
            k--;
            s.pop();
        }
        
        string res="";
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        
        if(res.length()==0)
            return "0";
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};