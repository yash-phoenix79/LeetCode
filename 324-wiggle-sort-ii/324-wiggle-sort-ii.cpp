class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>t=nums;
        sort(t.begin(),t.end());
        
        int i=n/2,j=n-1;
        if(n%2==0)
            i--;
        
        int k=0;
        int m=n/2;
        while(m--){
            nums[k++]=t[i--];
            nums[k++]=t[j--];
        }
        
        if(n%2)
            nums[k]=t[i];
        
    }
};