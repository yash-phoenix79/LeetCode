class Solution {
public:
    int minMoves(int t, int ma) {
        
        int res=0;
        while(t>1){
            
           if(ma>0){
               if(t%2==0){
                   ma--;
                   t/=2;
               }
                   
               else
                   t--;
               res++;
           }
            
            else{
                res+=(t-1);
                t=1;
            }
                
            
           
        }
        return res;
    }
};