class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size(),cnt=count(nums.begin(),nums.end(),val);
        
      for(int i=n-1;i>=0;i--){
          if(nums[i]==val)
              nums.erase(nums.begin()+i);
      }
     
        return n-cnt;
    }
};