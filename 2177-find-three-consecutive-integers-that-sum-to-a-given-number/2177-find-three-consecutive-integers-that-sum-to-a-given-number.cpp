class Solution {
public:
    vector<long long> sumOfThree(long long num) {
         vector<long long>res;
        if(num%3!=0)
            return res;
        long long x=(num/3)-1;
        res={x,x+1,x+2};
        return res;
    }
};