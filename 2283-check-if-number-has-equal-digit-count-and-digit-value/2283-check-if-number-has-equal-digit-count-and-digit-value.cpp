class Solution {
public:
    bool digitCount(string num) {
        int n=num.size();
        vector<int>check(n,0);
        
        for(auto x:num){
            if(x-'0'<n)
            check[x-'0']++;
        }
            
        
        for(int i=0;i<n;i++){
            if(num[i]-'0'!=check[i])
                return false;
        }
        return true;
    }
};