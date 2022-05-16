class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=1,h=n-1;
        int m,cnt;
        
        while(l<h){
            m=(l+h)/2;
            cnt=0;
            for(int n:nums)
                if(n<=m)
                    cnt++;
            if(cnt>m)
                h=m;
            else
                l=m+1;
        }
        return l;
    }
};