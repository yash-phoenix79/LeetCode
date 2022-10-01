class Solution {
public:
    vector<int> plusOne(vector<int>& dig) {
        
        int n=dig.size();
        int i=n-1;
        
        int car=1,sum=0;
        while(i>=0&&car){
            sum=dig[i]+car;
            dig[i]=sum%10;
            car=sum/10;
            i--;
        }
        
        if(car){
            vector<int>res={1};
            res.insert(res.end(),dig.begin(),dig.end());
            // for(auto x:res)
            // cout<<x<<endl;
            return res;
        }
        return dig;
    }
};