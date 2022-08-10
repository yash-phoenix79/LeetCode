class Solution {
public:
    #define N 1000000007
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        unordered_map<int,long>m;
        for( auto x:arr)
            m[x]=1;
        
        long cnt=0;
        for(int i=1;i<n;i++){
            cnt=0;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    if(m.find(arr[i]/arr[j])!=m.end())
                    {
                        cnt+=(m[arr[j]])*(m[arr[i]/arr[j]]);
                      
                    }
                }
            }
            m[arr[i]]+=cnt;
            
        }
        
        int res=0;
        for(auto x:m){
            res=(res+x.second)%N;
        }
        return res;
    }
};