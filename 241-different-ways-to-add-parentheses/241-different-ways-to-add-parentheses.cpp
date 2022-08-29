class Solution {
public:
    
    vector<int> recur(string s,int l,int r){
        if(l>r)
            return {1};
        if(l==r)
            return {s[l]-'0'};
        vector<int>res;
        for(int i=l;i<=r;i++){
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'){
                
                vector<int>left=recur(s,l,i-1);
                vector<int>right=recur(s,i+1,r);
                
                for(auto x:left){
                    for(auto y:right){
                        if(s[i]=='+')
                            res.push_back(x+y);
                        else if(s[i]=='-')
                            res.push_back(x-y);
                        else
                            res.push_back(x*y);
                    }
                }
                
            }
        }
        if(res.empty())
            return {stoi(s.substr(l,r-l+1))};
        return res;
        
    }
    
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.length();
        return recur(expression,0,n-1);
    }
};