class Solution {
public:
    
     vector<vector<int>>res;
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();
        sort(begin(nums),end(nums));
        
        for(int i=n-1;i>=2;i--){
            int t=-nums[i];
            int l=0,r=i-1;
            
            while(l<r){
                if(nums[l]+nums[r]<t)
                    l++;
                else if(nums[l]+nums[r]>t)
                    r--;
                else{
                    res.push_back({nums[i],nums[l],nums[r]});
                    int x=l,y=r;
                    while(x<r&&nums[x]==nums[l]){
                        x++;
                    }
                    while(y>l&&nums[y]==nums[r])
                        y--;
                    l=x,r=y;
                }
            }
            
            while(i-1>=2&&nums[i-1]==nums[i])
                i--;
            
        }
        return res;
    }
};