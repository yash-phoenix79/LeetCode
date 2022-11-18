class Solution {
public:
    
    void solve(int n,vector<int>&num){
        
        int x=n+n;
        for(;x<num.size();x+=n){
            // cout<<x<<" ";
             num[x]=0;
        }
           
        
    }
    
    int countPrimes(int n) {
        
        if(n==0)
            return 0;
        
        int c=sqrt(n);
        vector<int>num(n+1,1);
        
        num[0]=num[1]=0;
        
        for(int i=2;i<=c;i++){
            if(num[i]==1)
                solve(i,num);
        }
        
        int res=0;
        
        for(int i=2;i<n;i++)
            if(num[i])
                res++;
        
        return res;
        
    }
};