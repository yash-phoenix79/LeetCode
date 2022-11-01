class Solution {
public:
    string minimizeResult(string exp) {
        
        int n=exp.length();
        
        string res="";
        int val=1000000000;
        
        int idx=0;
        while(idx<n&&exp[idx]!='+')
            idx++;
        idx++;
        
        for(int i=0;i<idx-1;i++){
            for(int j=idx;j<n;j++){
                string sub=exp.substr(0,i)+"("+exp.substr(i,j-i+1)+")"+exp.substr(j+1,n);
                int a=0,b=0,c=0,d=0,k=0;
                
                for(;sub[k]!='(';k++)
                    a=a*10+(sub[k]-'0');
                k++;
                for(;sub[k]!='+';k++)
                    b=b*10+(sub[k]-'0');
                k++;
                for(;sub[k]!=')';k++)
                    c=c*10+(sub[k]-'0');
                k++;
                for(;k<sub.length();k++)
                    d=d*10+(sub[k]-'0');
                
                b+=c;
                if(a==0)a=1;
                if(d==0)d=1;
                
                if(a*b*d<val){
                    val=a*b*d;
                    res=sub;
                }
                
            }
        }
        
        return res;
        
        
    }
};