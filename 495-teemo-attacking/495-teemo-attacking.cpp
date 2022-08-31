class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int du) {
     
        int res=0,n=t.size();
        int i=0;
        
        while(i<n){
            int cur=t[i]+du-1;
           if(i+1<n){
               if(t[i+1]>cur)
                   res+=du;
               else
                   res+=t[i+1]-t[i];
           }
            i++;
        }
        res+=du;
        return res;
    }
};