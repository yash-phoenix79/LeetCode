class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1)
            return INT_MAX;
        
        long dvs=divisor,dvd=dividend,ans=0,temp,m=1;
        int sign=(dvs>0==dvd>0)?1:-1;
        dvs=labs(dvs),dvd=labs(dvd);
        
        while(dvd-dvs>=0){
            temp=dvs,m=1;
            while(temp<<1<=dvd){
                temp<<=1;
                m<<=1;
            }
            ans+=m;
            dvd-=temp;
        }
        return sign*ans;
    }
};