class Solution {
public:
    
    int merge(vector<int>&nums,int l,int m,int r){
        int cnt=0;
        int j=m+1;
       for(int i=l;i<=m;i++){
           while(j<=r&&nums[i]>2LL*nums[j])
               j++;
           cnt+=(j-m-1);
       }
        
        int i=l,k=l;
        j=m+1;
        vector<int>temp;
        while(i<=m&&j<=r){
            if(nums[i]<=nums[j])
              temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        while(i<=m)
             temp.push_back(nums[i++]);
        while(j<=r)
            temp.push_back(nums[j++]);
        
        for(int i=l;i<=r;i++)
            nums[i]=temp[i-l];
        return cnt;
    }
    
    int mergeSort(vector<int>& nums,int l,int r){
        if(l>=r)
            return 0;
        int m=(l+r)/2;
        int inv=mergeSort(nums,l,m);
        inv+=mergeSort(nums,m+1,r);
        inv+=merge(nums,l,m,r);
        return inv;
    }
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};