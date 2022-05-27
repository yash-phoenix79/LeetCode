class Solution {
public:
    int numberOfSteps(int num) {
        int cnt=0;
        while(num){
            cnt++;
            num=num%2?--num:num/2;
        }
        return cnt;
    }
};