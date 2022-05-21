class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        if(n<3)
            return ans;
        
     sort(nums.begin(),nums.end());
        
      for(int i=0;i<n-2;i++){
          int t=-nums[i];
          int front=i+1,back=n-1;
          while(front<back){
              if(nums[front]+nums[back]==t){
                  ans.push_back({-t,nums[front++],nums[back--]});
                  while(front<back&&nums[front]==nums[front-1])front++;
                  while(front<back&&nums[back]==nums[back+1])back--;
              }
              else if(nums[front]+nums[back]<t)
                  front++;
              else
                  back--;
          }
          while(i+1<n&&nums[i]==nums[i+1])i++;
      }
        
        return ans;
    }
};