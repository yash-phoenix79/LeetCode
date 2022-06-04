class Solution {
public:
    
    int solve(int idx,int n,int perm)
    {
      if(idx>n)
          return 1;
        int res=0;
        for(int i=1;i<=n;i++){
            if((i%idx==0)||(idx%i==0)){
                if(!(perm&(1<<i)))
                res+=solve(idx+1,n,perm|(1<<i));
            }
            }
           return res;
        }
    
    int countArrangement(int n) {
        int perm=0;
        return solve(1,n,perm);
    }
};