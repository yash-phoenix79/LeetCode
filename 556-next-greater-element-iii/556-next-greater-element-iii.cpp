class Solution {
public:
    int nextGreaterElement(int n) {
        auto t=to_string(n);
        next_permutation(begin(t),end(t));
        auto temp=stol(t);
        return (temp>INT_MAX||temp<=n)?-1:temp;
    }
};