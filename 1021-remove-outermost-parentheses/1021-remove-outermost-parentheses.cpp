class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        stack<char>st;
        
        int i=0,n=s.size();
        while(i<n){
            if(st.empty())
                st.push(s[i]);
            else if(s[i]==')'){
                if(st.size()!=1)
                {
                   ans+=s[i];
                }
                
                    st.pop();
                
            }
             else if(s[i]=='('){
                  st.push(s[i]);
                 ans+=s[i];
             }
              i++;  
            
        }
        return ans;
    }
};