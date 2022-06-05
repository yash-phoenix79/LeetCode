class Solution {
public:
     vector<string> ans;
    
    void findPar(int open,int close,string temp,int n){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(open<n)
            findPar(open+1,close,temp+"(",n);
        if(close<open)
            findPar(open,close+1,temp+")",n);
        
    }
    
    vector<string> generateParenthesis(int n) {
        
      findPar(0,0,"",n);  
      return ans;
    }
};