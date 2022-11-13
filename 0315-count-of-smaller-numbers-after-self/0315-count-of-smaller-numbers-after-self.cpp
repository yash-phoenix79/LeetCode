class Solution {
public:
    
    void merge(vector<pair<int,int>>&a,vector<int>&cnt,int l,int m,int r){
        
        vector<pair<int,int>>t(r-l+1);
        int i=l,j=m+1,k=0;
        
        while(i<=m&&j<=r){
            if(a[i].first>a[j].first){
                cnt[a[i].second]+=(r-j+1);
                t[k++]=a[i++];
            }
            else
                t[k++]=a[j++];
        }
        
        while(i<=m)
            t[k++]=a[i++];
        while(j<=r)
            t[k++]=a[j++];
        
        for(int i=l;i<=r;i++)
            a[i]=t[i-l];
        
    }
    
    void mergeSort(vector<pair<int,int>>&a,vector<int>&cnt,int l,int r){
        if(l<r){
            int m=(l+r)/2;
            mergeSort(a,cnt,l,m);
            mergeSort(a,cnt,m+1,r);
            merge(a,cnt,l,m,r);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>cnt(n,0);
        
        vector<pair<int,int>>a;
        for(int i=0;i<n;i++){
            a.push_back({nums[i],i});
        }
        
        mergeSort(a,cnt,0,n-1);
        return cnt;
    }
};