class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        for(int i=1;i<=n;i++)
            ans+='0'+i;
        if(n==1||k==1)
            return ans;
        while(--k){
         int idx1,idx2;
            for(int i=n-2;i>=0;i--){
                if(ans[i]<ans[i+1]){
                    idx1=i;
                    break;
                }
            }
            
            for(int i=n-1;i>=0;i--){
                if(ans[i]>ans[idx1]){
                    idx2=i;
                    break;
                }
            }
            
            swap(ans[idx1],ans[idx2]);
            reverse(ans.begin()+idx1+1,ans.end());
            
        }
        
        return ans;
        
    }
};