class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>s;
        int sum=0;
        while(n!=1&&s[n]==0){
            s[n]++;
            sum=0;
            while(n){
                sum+=(pow(n%10,2));
                n/=10;
            }
            n=sum;
        }
        return n==1;
    }
};