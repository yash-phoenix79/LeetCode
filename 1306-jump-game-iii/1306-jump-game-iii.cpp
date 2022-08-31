class Solution {
public:
    vector<int>vis;
    
    bool find(vector<int>&arr,int start,int n){
        if(vis[start]==1)
            return false;
        vis[start]=1;
        if(arr[start]==0)
            return true;
        bool res=false;
        if(start+arr[start]<n)
            res=res||find(arr,start+arr[start],n);
        if(start-arr[start]>=0)
            res=res||find(arr,start-arr[start],n);
        return res;
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vis=vector<int>(n,0);
        return find(arr,start,n);
    }
};