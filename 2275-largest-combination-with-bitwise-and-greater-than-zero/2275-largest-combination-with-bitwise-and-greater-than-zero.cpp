class Solution {
public:
    int largestCombination(vector<int>& can) {
        
        int n=can.size();
        int maxi=*max_element(can.begin(),can.end());
        
        int res=0;
        for(int i=1;i<=maxi;i<<=1){
            int cnt=0;
            for(auto x:can){
                if((x&i)>0)cnt++;
            }
            res=max(res,cnt);
        }
        return res;
    }
};