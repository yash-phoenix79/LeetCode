class Solution {
public:
    int countCollisions(string dir) {
        
        int n=dir.length();
        int i=0,r=0;
        int res=0;
        
        while(i<n&&dir[i]=='L')
            i++;
        
        for(;i<n;i++){
            if(dir[i]=='R')
                r++;
            else{
                res+=(dir[i]=='L'?r+1:r);
                r=0;
            }
        }
        return res;
    }
};