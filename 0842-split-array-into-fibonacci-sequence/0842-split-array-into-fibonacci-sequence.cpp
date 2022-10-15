class Solution {
public:
    
    vector<int>res;
    
    void find(int idx,string num,vector<int>sol){
        if(idx==num.length()&&sol.size()>2)
        {
            res=sol;
            return;
        }
        
        long long n=0;
        for(int i=idx;i<num.length();i++){
            n=n*10+(num[i]-'0');
            if(n>INT_MAX)return;
            if(num[idx]=='0'&&i>idx)return;
            if(sol.size()<2||n==(long long)sol.back()+(long long)sol[sol.size()-2]){
                sol.push_back(n);
                find(i+1,num,sol);
                sol.pop_back();
            }
        }
        
    }
    
    vector<int> splitIntoFibonacci(string num) {
        
        vector<int>sol;
        find(0,num,sol);
        return res;
        
    }
};