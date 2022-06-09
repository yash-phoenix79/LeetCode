class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        
        while(num/10){
            sum=0;
            while(num){
            sum+=(num%10);
            num/=10;
            
        }
            num=sum;
        }
        return num;
        
    }
};