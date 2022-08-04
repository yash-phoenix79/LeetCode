class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int l=1,r=num;
        long long int m=0;
        
        
        while(m*m!=num&&l<=r){
            m=(l+r)/2;
            if(m*m>num)
                r=m-1;
            else
                l=m+1;
        }
        
        return m*m==num;
        
    }
};