class Solution {
public:
    
    #define N 1000000007
    
    int countVowelPermutation(int n) {
        long a=1,e=1,i=1,o=1,u=1;
        
        long a2,e2,i2,o2,u2;
        
        for(int j=2;j<=n;j++){
            a2=(e+i+u)%N;
            e2=(a+i)%N;
            i2=(e+o)%N;
            o2=i;
            u2=(i+o)%N;
            
            a=a2,e=e2,i=i2,o=o2,u=u2;
        }
        
        return (a+e+i+o+u)%N;
        
    }
};