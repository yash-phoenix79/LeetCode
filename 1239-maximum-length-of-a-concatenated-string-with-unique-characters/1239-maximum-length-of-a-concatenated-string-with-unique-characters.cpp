class Solution {
public:
    
    int res=0;
    
    void find(int idx,vector<string>& arr,int n,vector<int>al,int len){
        
        res=max(res,len);
        if(idx==n)return;
        
        find(idx+1,arr,n,al,len);
        
        
        int dis=arr[idx].size();
        for(int i=0;i<dis;i++){
            
            if(al[arr[idx][i]-'a']!=0)
                return;
            al[arr[idx][i]-'a']++;
        }
        
        find(idx+1,arr,n,al,len+arr[idx].size());
        
    }
    
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        vector<int>al(26,0);
        find(0,arr,n,al,0);
        return res;
    }
};