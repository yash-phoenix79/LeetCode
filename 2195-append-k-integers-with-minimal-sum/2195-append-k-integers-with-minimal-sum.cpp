class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
        sort(begin(nums),end(nums));
        
        long long sum=0;
        int i=0,prev=0;
        
        while(k>0&&i<nums.size()){
            int len=nums[i]-prev-1;
            if(len>k)
                len=k;
            if(len>0){
                long long start=prev;
                long long end=prev+len;
                long long s=(end*(end+1))/2-(start*(start+1))/2;
                sum+=s;
                k-=len;
            }
            prev=nums[i];
            i++;
        }
        
        if(k>0){
            long long start=nums[nums.size()-1];
            long long end=start+k;
            long long s=(end*(end+1))/2-(start*(start+1))/2;
            sum+=s;
        }
        return sum;
    }
};