class Solution {
public:
    
    int check(int n){
        int res=0;
        
        while(n){
            res=res+((n%10)*(n%10));
        n/=10; 
        }
       
        return res;
    }
    
    bool isHappy(int n) {
        
        int s=check(n);
        int f=check(check(n));
        
        while(s!=f&&s!=n){
            s=check(s);
            f=check(check(f));
        }
        
        return s==1;
        
    }
};