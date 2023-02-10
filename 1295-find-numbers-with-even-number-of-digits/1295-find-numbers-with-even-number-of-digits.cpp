class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int n=nums.size();
        
        int res=0;
        
        for(int i=0;i<n;i++){
            
            int cur=nums[i];
            int cnt=0;
            while(cur){
                cnt++;
                cur/=10;
            }
            if(cnt%2==0)
                res++;
        }
        
        return res;
        
    }
};