class Solution {
public:
    int nextGreaterElement(int n) {
        if(n/10==0)
            return -1;
        string t=to_string(n);
        int n1=t.length();
        int idx1=-1,idx2=-1;
        
        for(int i=n1-2;i>=0;i--){
            if(t[i]<t[i+1]){
                idx1=i;
                break;
            }
                
        }
        if(idx1==-1)
            return -1;
        for(int i=n1-1;i>=0;i--){
            if(t[i]>t[idx1]){
                idx2=i;
                break;
            }
        }
        swap(t[idx1],t[idx2]);
        reverse(t.begin()+idx1+1,t.end());
        
        long ans= stol(t);
        if(ans>INT_MAX)
            ans=-1;
        return (int)ans;
    }
};