class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>res(l.size());
        
        for(int i=0;i<l.size();i++){
            vector<int>t(nums.begin()+l[i],nums.begin()+r[i]+1);
            sort(t.begin(),t.end());
            if(t.size()<3)
                res[i]=true;
            else{
                int j;
                  for(j=2;j<t.size();j++)
                      if(t[j]-t[j-1]!=t[1]-t[0])
                          break;
                res[i]=j==t.size()?true:false;
            }
          
        }
        return res;
    }
};