class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        
        int n=exp.length();
        
        int l=0,r=n-1;
        vector<int>res;
        
        bool check=false;
        
        for(int i=0;i<n;i++){
            if(!isdigit(exp[i])){
                check=true;
                vector<int>lt= diffWaysToCompute(exp.substr(0,i));
                vector<int>rt= diffWaysToCompute(exp.substr(i+1));
                
                for(auto x:lt){
                    for(auto y:rt){
                        if(exp[i]=='-')
                            res.push_back(x-y);
                        else if(exp[i]=='+')
                            res.push_back(x+y);
                        else
                            res.push_back(x*y);
                    }
                }
                
            }
        }
        
        if(!check)
            return {stoi(exp)};
        return res;
        
        
    }
};