class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        
        int len=f.size();
        
        if(n==0)return true;
        
        int i=0;
        int t=n;
        while(i<len){
            
            if(f[i]==1){
                i+=2;
                continue;
            }
            
            if((i==len-1||i+1<len&&f[i+1]==0)){
                t--;
                i+=2;
                if(t==0)
                    return true;
                continue;
            }
              
            i++;
            
        }
        
        return t==0;
        
    }
};