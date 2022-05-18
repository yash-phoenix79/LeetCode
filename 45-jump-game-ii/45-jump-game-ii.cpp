class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dis(n,INT_MAX);
        
        if(n==1)
            return 0;
        
        dis[0]=0;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                dis[i+j]=min(dis[i+ j],dis[i]+1);
                if(dis[n-1]!=INT_MAX)
                    return dis[n-1];
            }
                
        }
        return dis[n-1];
    }
};