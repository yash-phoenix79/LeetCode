class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
     
        int n=nums.size();
        string res="";
        
        set<string>s;
        
        for(int i=0;i<n;i++){
            string t="";
            int cnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]%p==0)
                    cnt++;
                if(cnt>k)
                    break;
                t+=to_string(nums[j]);
                t+="_";
                s.insert(t);
            }
        }
        
        return s.size();
        
    }
};