class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int>ans;
        int n=exp.length();
        int check=1;
        
        for(int i=0;i<n;i++){
            if(!isdigit(exp[i])){
                check=0;
                vector<int>l= diffWaysToCompute(exp.substr(0,i));
                vector<int>r= diffWaysToCompute(exp.substr(i+1));
                for(auto x:l){
                    for(auto y:r){
                        if(exp[i]=='+')
                            ans.push_back(x+y);
                        else if(exp[i]=='-')
                            ans.push_back(x-y);
                        else
                            ans.push_back(x*y);
                    }
                }
                
            }
        }
        if(check)
            return{stoi(exp)};
        return ans;
    }
};