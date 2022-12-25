class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        
        int n=nums.size();
        int m=q.size();
        
        vector<int>res(m);
        
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<n;i++)
            nums[i]+=nums[i-1];
        
        for(int i=0;i<m;i++){
            
            if(q[i]<nums[0]){
                res[i]=0;
                continue;
            }
            
            else if(q[i]>nums[n-1]){
                res[i]=n;
                continue;
            }
            
            int pos=upper_bound(begin(nums),end(nums),q[i])-begin(nums);
            
            res[i]=pos;
            
        }
        
        return res;
        
    }
};