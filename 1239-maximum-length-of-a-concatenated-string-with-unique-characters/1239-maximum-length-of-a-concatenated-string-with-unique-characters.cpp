class Solution {
public:
    
    int res=0;
    
    void find(int idx,vector<string>& arr,int n,int mask,int len){
        
        res=max(res,len);
        if(idx==n)return;
        
        find(idx+1,arr,n,mask,len);
        
        
        int dis=arr[idx].size();
        for(int i=0;i<dis;i++){
            
           int t=arr[idx][i]-'a';
            if(mask&(1<<t))
                return;
            mask=mask|(1<<t);
        }
        
        find(idx+1,arr,n,mask,len+arr[idx].size());
        
    }
    
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        int mask=0;
        find(0,arr,n,mask,0);
        return res;
    }
};