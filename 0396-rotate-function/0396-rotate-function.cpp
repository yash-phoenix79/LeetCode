class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
     
        int n=nums.size();
        int sum=0;
        int fn=0,res=INT_MIN;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            fn+=i*nums[i];
        }
        
        int l=1,r;
        res=max(res,fn);
        
        while(l<=n){
            
            r=l+n-1;
            int add=(n)*nums[r%n];
            
            fn=fn+add-sum;
            
            res=max(res,fn);
            l++;
        }
        
        return res;
        
    }
};