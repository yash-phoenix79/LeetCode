class Solution {
public:
    string addBinary(string a, string b) {
        
        int n=a.size(),m=b.size();
        if(n<m)
            swap(a,b);
        n=a.size(),m=b.size();
        int i=a.size()-1,j=b.size()-1;
        int sum,carry=0;
        while(i>=0&&j>=0){
            sum=(a[i]-'0')+(b[j]-'0')+carry;
            a[i]=(sum%2)+'0';
            carry=sum/2;
            i--,j--;
        }
        
        while(i>=0){
            sum=(a[i]-'0')+carry;
            a[i]=(sum%2)+'0';
            carry=sum/2;
            i--;
        }
        
        if(carry){
            string t="1";
            t.append(a);
            return t;
        }
        return a;
    }
};