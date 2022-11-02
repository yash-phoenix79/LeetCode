class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int res=0;
       stack<char>st;
        
        for(auto x:s){
            if(x=='('){
              
                st.push('(');
            }
            else{
                if(!st.empty()&&st.top()=='(')
                    st.pop();
                else
                    st.push(')');
            }
        }
        
        return st.size();
        
    }
};