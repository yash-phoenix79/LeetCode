class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int>res;
        
        if(n%2){
            res.push_back(0);
            n--;
        }
            
        int t=n/2;
        int x=1;
        while(t--){
            res.push_back(x);
            res.push_back(-x);
            x++;
        }
        
            return res;
        
    }
};