class Solution {
public:
    
    void merge(vector<int>&nums,int l,int m,int r){
        
        vector<int>t(r-l+1);
        int i=l,j=m+1,k=0;
        
        while(i<=m&&j<=r){
            if(nums[i]<=nums[j])
                t[k++]=nums[i++];
            else
                t[k++]=nums[j++];
        }
        
        while(i<=m)
            t[k++]=nums[i++];
        while(j<=r)
            t[k++]=nums[j++];
        
        for(int i=l;i<=r;i++)
            nums[i]=t[i-l];
        
    }
    
    void mergeSort(vector<int>&nums,int l,int r){
        
        if(l<r){
            int m=(l+r)/2;
            mergeSort(nums,l,m);
            mergeSort(nums,m+1,r);
            merge(nums,l,m,r);
        }
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};