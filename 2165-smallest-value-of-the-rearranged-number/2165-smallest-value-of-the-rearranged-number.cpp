class Solution {
public:
    long long smallestNumber(long long num) {
       
        if(num==0)
            return 0;
        
        bool neg=false;
        if(num<0)
            neg=true;
        
        num=abs(num);
        string t=to_string(num);
        sort(begin(t),end(t),[](auto &a,auto &b){
            return a>b;
        });
        
        if(neg)
        {
          
            num=-1*stoll(t);
            return num;
        }
        
        int i=t.size()-1;
        while(i>=0&&t[i]=='0')
            i--;
        swap(t[i],t[t.size()-1]);
        reverse(begin(t),end(t));
        num=stoll(t);
            return num;
    }
};