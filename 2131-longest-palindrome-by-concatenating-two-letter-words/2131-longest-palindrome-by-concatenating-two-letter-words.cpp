class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        int res=0;
       unordered_map<string,int>m,m1;
        bool flag=true;
       for(auto x:words){
           
           if(x[0]==x[1]){
               m1[x]++;
              continue;
           }
              
           
           string t=x;
           swap(t[0],t[1]);
           if(m.find(t)!=m.end()){
               res+=4;
               if(m[t]==1)
               m.erase(t);
               else
                   m[t]--;
           }
           else
               m[x]++;
           
       }
        
        for(auto x:m1){
            int cnt=x.second;
            if(cnt%2&&flag){
                res+=2;
                flag=false;
            }
            int p=cnt/2;
            p*=2;
            res+=(2*p);
        }
        
        return res;
        
    }
};