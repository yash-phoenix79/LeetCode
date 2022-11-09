class Solution {
public:
    
    int N=1000000007;
    
    int sumSubarrayMins(vector<int>& arr) {
        
        int n=arr.size();
        
        vector<int>arr1(n),arr2(n);
        
        stack<pair<int,int>>s;
        
        s.push({INT_MIN,-1});
        
        for(int i=0;i<n;i++){
            int cnt=1;
            
            while(!s.empty()&&arr[i]<=s.top().first){
                cnt+=s.top().second;
                s.pop();
            }
            
            s.push({arr[i],cnt});
            arr1[i]=cnt;
            
        }
        
      
        s.push({INT_MIN,n});
        
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!s.empty()&&arr[i]<s.top().first){
                cnt+=s.top().second;
                s.pop();
            }
            s.push({arr[i],cnt});
            arr2[i]=cnt;
        }
        
        long long res=0;
        for(int i=0;i<n;i++){
            res=(res+(long long)((long long)(arr[i]%N)*(long long)(arr1[i]%N)*(long long)(arr2[i]%N))%N)%N;
        }
        
        return res;
        
    }
};