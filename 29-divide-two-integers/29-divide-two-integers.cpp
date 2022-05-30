class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1)
            return INT_MAX;
        long dvd=dividend,dvs=divisor,ans=0,temp=dvs,m=1;
        
        int sign=(dvd>0==dvs>0)?1:-1;
        dvd=labs(dvd),dvs=labs(dvs);
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