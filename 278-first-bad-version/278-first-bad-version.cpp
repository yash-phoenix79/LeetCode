// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int l=1,r=n;
        long long int m;
        int res=0;
        while(l<=r){
            m=( long long int )(l+r)/2;
            if(isBadVersion(m)){
                res=m;
                r=m-1;
            }
            else
                l=m+1;
        }
        return res;
    }
};