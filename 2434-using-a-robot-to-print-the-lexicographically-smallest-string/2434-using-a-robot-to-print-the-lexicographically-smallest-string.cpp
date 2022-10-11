class Solution {
public:
    
    char low(vector<int>&freq){
        
        for(int i=0;i<26;i++){
            if(freq[i]!=0)return i+'a';}
        
        return 'a';
    }
    
    string robotWithString(string s) {
     
        stack<char>st;
        int n=s.length();
        vector<int>freq(26,0);
        for(auto x:s)
            freq[x-'a']++;
        
        string res="";
        
        for(auto x:s){
            st.push(x);
            freq[x-'a']--;
            while(st.size()>0&&st.top()<=low(freq)){
                res+=st.top();
                st.pop();
            }
        }
        
        while(!st.empty()){
            res+=st.top();
                st.pop();
        }
        
        return res;
        
    }
};