class Solution {
public:
    
    void merge(vector<int>&cnt,vector<pair<int,int>>&arr,int l,int m,int r){
        vector<pair<int,int>>temp(r-l+1);
        int k=0;
        int i=l;
        int j=m+1;
        
        while(i<=m&&j<=r){
            if(arr[i].first>arr[j].first){
                cnt[arr[i].second]+=r-j+1;
                temp[k++]=arr[i++];
            }
                
            else{
                temp[k++]=arr[j++];
            }
        }
        
        while(i<=m)
           temp[k++]=arr[i++];
        
        while(j<=r)
           temp[k++]=arr[j++];
        
        for(int i=l;i<=r;i++)
            arr[i]=temp[i-l];
        
        
            
        
    }
    
    void mergeSort(vector<int>&cnt,vector<pair<int,int>>&arr,int l,int r){
        if(l<r){
            int m=(l+r)/2;
            mergeSort(cnt,arr,l,m);
            mergeSort(cnt,arr,m+1,r);
            merge(cnt,arr,l,m,r);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>cnt(n,0);
        
        vector<pair<int,int>>arr(n);
        
        for(int i=0;i<n;i++){
            arr[i]={nums[i],i};
        }
        
        mergeSort(cnt,arr,0,n-1);
        
        return cnt;
        
    }
};