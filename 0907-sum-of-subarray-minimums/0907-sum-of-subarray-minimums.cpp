class Solution {
public:
    
    int N=1000000007;
    
    int sumSubarrayMins(vector<int>& arr) {
        
        int n=arr.size();
        vector<int>l(n,-1),r(n,n);
        
        stack<int>s;
        
        for(int i=0;i<n;i++){
            
            while(s.size()&&arr[i]<arr[s.top()])s.pop();
            if(s.size())l[i]=i-s.top();
            else l[i]=i+1;
            s.push(i);
        }
        
        while(s.size())s.pop();
        
        for(int i=n-1;i>=0;i--){
            while(s.size()&&arr[i]<=arr[s.top()])s.pop();
            if(s.size())r[i]=s.top()-i;
            else r[i]=n-i;
            s.push(i);
        }
        
        long long res=0;
        
        for(int i=0;i<n;i++){
            long long prod=(l[i]*r[i])%N;
            prod=(prod*arr[i])%N;
            res=(res+prod)%N;
        }
        
        return res%N;
        
    }
};