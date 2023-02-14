class Solution {
public:
    string addBinary(string a, string b) {
        
        if(a.length()<b.length())
            swap(a,b);
        
        int n=a.length(),m=b.length();
        
        int car=0,sum=0;
        
        int i=n-1,j=m-1;
        
        while(j>=0){
            
            sum=a[i]-'0'+b[j]-'0'+car;
            a[i]=sum%2+'0';
            car=sum/2;
            
            i--,j--;
            
        }
        
        if(car){
            
            while(i>=0){
                sum=a[i]-'0'+car;
                a[i]=sum%2+'0';
                car=sum/2;
                i--;
            }
            
            
            
        }
        
        if(car){
            return "1"+a;
        }     
        return a;
        
        
    }
};