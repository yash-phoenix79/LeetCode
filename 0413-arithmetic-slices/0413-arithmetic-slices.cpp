class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size();
        int cnt=0,diff;
        
        for(int i=0;i<n-2;i++){
            diff=nums[i+1]-nums[i];
            for(int j=i+2;j<n;j++){
                if(nums[j]-nums[j-1]==diff)
                    cnt++;
                else
                    break;
            }
        }
        return cnt;
    }
};