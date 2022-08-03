class Solution {
public:
    int arrangeCoins(int n) {
        
        int cnt=0;
        int x=1;
        while(n-x>=0){
            n-=x;
            x++;
            cnt++;
        }
        return cnt;
    }
};