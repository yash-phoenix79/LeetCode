class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>res;
        
        int n=nums.size();
        
        // sort(begin(nums),end(nums));
        
        unordered_map<int,int>m;
        unordered_set<int>s;
        
        for(int i=1;i<=n;i++)
            s.insert(i);
        
        int a,b=-1;
        
        for(int i=0;i<n;i++){
            
          if(s.find(nums[i])!=s.end())
              s.erase(nums[i]);
            
            if(++m[nums[i]]>1)
                a=nums[i];
            
        }
        
        b=*s.begin();
        
        return {a,b};
        
        
    }
};