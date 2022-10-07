class Solution {
public:
    
    bool check(long long n1,long long n2,string s,bool find){
        if(s.length()==0&&find)
            return true;
        long long n3=n1+n2;
       
        string req=to_string(n3);
         long long len=min(req.length(),s.length());
        if(s.substr(0,len)==req)
            return check(n2,n3,s.substr(len),true);
        return false;
    }
    
    bool isAdditiveNumber(string num) {
        
        int n=num.length();
        for(int i=1;i<n-1;i++){
            long long n1=stol(num.substr(0,i));
            if(to_string(n1)!=num.substr(0,i))
                break;
            for(int j=i+1;j<n;j++){
                long long n2=stol(num.substr(i,j-i));
                if(to_string(n2)!=num.substr(i,j-i))
                    break;
                
                if(check(n1,n2,num.substr(j),false))
                    return true;
                
            }
        }
        return false;
    }
};