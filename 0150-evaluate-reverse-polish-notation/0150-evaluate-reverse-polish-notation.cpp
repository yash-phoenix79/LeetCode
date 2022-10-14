class Solution {
public:
    int evalRPN(vector<string>& t) {
        
        stack<long long>s;
        
        for(auto x:t){
            
            if(x!="+"&&x!="-"&&x!="*"&&x!="/")
                s.push(stoi(x));
            else{
                
                long long a =s.top();
                s.pop();
                long long b=s.top();
                s.pop();
                
                if(x=="+")
                    s.push(b+a);
                else if(x=="-")
                    s.push(b-a);
                else if(x=="*")
                    s.push(b*a);
                else
                    s.push(b/a);
                
            }
            
        }
        
        return s.top();
        
    }
};