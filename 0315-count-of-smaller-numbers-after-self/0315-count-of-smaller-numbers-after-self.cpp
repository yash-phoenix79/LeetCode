class Solution {
public:
    
    void merge(vector<pair<int,int>>&arr,int l,int m,int r,vector<int>&cnt){
        
        vector<pair<int,int>>t(r-l+1);
        int i=l,j=m+1;
        int k=0;
        while(i<=m&&j<=r){
            if(arr[i].first>arr[j].first)
            {
                cnt[arr[i].second]+=r-j+1;
                t[k++]=arr[i++];
                
            }
            else
                t[k++]=arr[j++];
            
        }
        
        while(i<=m)
            t[k++]=arr[i++];
        while(j<=r)
            t[k++]=arr[j++];
        
        for(i=l;i<=r;i++)
            arr[i]=t[i-l];
        
    }
    
    void mergeSort(vector<pair<int,int>>&arr,int l,int r,vector<int>&cnt){
        
        if(l<r){
            int m=(l+r)/2;
            mergeSort(arr,l,m,cnt);
            mergeSort(arr,m+1,r,cnt);
            merge(arr,l,m,r,cnt);
        }
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>cnt(n,0);
        vector<pair<int,int>>arr;
        
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        
        mergeSort(arr,0,n-1,cnt);
        return cnt;
        
    }
};