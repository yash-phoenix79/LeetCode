class Solution {
public:
    string pushDominoes(string d) {
        d='L'+d+'R';
        int n=d.length();
        string res="";
        
        for(int i=0,j=1;j<n;j++){
            if(d[j]=='.')continue;
            
            int midLen=j-i-1;
            if(i>0)
             res+=d[i];
            
            if(d[i]==d[j])
                res+=string(midLen,d[i]);
            else if(d[i]=='L'&&d[j]=='R')
                res+=string(midLen,'.');
            else
                res+=string(midLen/2,'R')+string(midLen%2,'.')+string(midLen/2,'L');
            i=j;
        }
        return res;
    }
};