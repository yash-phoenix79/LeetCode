class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        int sum=0;
        while(n!=1&&s.find(n)==s.end()){
            s.insert(n);
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