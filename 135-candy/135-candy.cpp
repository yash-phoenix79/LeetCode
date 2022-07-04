class Solution {
public:
    int candy(vector<int>& r) {
        
        int n=r.size();
        vector<int>num(n,1);
        
        for(int i=1;i<n;i++){
            if(r[i]>r[i-1])
                num[i]=num[i-1]+1;
        }
        
        for(int i=n-1;i>0;i--){
            if(r[i-1]>r[i])
                num[i-1]=max(num[i-1],num[i]+1);
        }
        
        int res=0;
        for(int i=0;i<n;i++)
            res+=num[i];
        
        return res;
        
    }
};