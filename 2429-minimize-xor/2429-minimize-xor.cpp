class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
       
        int m=__builtin_popcount(num1);
         int n=__builtin_popcount(num2);
        
        cout<<m<<" "<<n<<endl;
        
        if(m==n)return num1;
        
        int c=0;
        if(m>n){
            while(n--){
                int pos=0;
                int t=num1;
                while(t>0){
                    t=t>>1;
                    pos++;
                }
                pos--;
                num1=num1&(~(1<<pos));
                // cout<<pos<<endl;
                c=c|(1<<pos);
            }
            return c;
        }
        
        
      int s=num1,i=0;
        n-=m;
       cout<<n<<endl;
        while(n>0){
            if(!(s&1)){
                num1=num1|((1<<i));
                n--;
                if(n==0)
                    break;
                cout<<i<<endl;
            }
            i++;
            s>>=1;
        }
        return num1;
    }
};