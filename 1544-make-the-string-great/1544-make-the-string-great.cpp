class Solution {
public:
    string makeGood(string s) {
        int n=s.length();
        stack<char>st;
        
        for(int i=0;i<n;i++){
            if(st.empty())
                st.push(s[i]);
            else if(!st.empty()&&tolower(st.top())==tolower(s[i])&&st.top()!=s[i]){
           
                    st.pop();
            }
            else
                st.push(s[i]);
        }
        
        string res="";
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};