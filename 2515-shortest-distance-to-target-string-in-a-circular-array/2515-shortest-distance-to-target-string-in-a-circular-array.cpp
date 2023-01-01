class Solution {
public:
    int closetTarget(vector<string>& w, string t, int s) {
        
        int n=w.size();
        
        int l=s,r=s,res=0;
        
        while(w[l]!=""&&w[r]!=""){
            
            if(w[l]==t||w[r]==t)
                return res;
            res++;
            w[l]=w[r]="";
            l=(l-1+n)%n;
            r=(r+1)%n;
            
        }
        return -1;
    }
};