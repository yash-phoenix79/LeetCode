class Solution {
public:
    
    int res=INT_MAX;
    vector<int>buc;
    void find(int idx,vector<int>& coo,int k,int n){

        if(idx>=n){
            int t=INT_MIN,i;
            for(i=0;i<k;i++){
                
                t=max(t,buc[i]);
            }

            res=min(res,t);
            return;
        }
            
        
        for(int i=0;i<k;i++){
            
          buc[i]+=coo[idx];
            find(idx+1,coo,k,n);
          buc[i]-=coo[idx];
            if(buc[i]==0)break;
        }
        
    }
    
    int distributeCookies(vector<int>& coo, int k) {
        
        int n=coo.size();
       buc=vector<int>(k,0);
        find(0,coo,k,n);
        
        return res;
        
    }
};