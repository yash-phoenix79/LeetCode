class Solution {
public:
    int bagOfTokensScore(vector<int>& tok, int p) {
        
        int res=0,sc=0,l=0,r=tok.size()-1;
        sort(begin(tok),end(tok));
        while(l<=r){
            if(p>=tok[l]){
                p-=tok[l++];
                res=max(res,++sc);
            }
            else if(sc>0){
                sc--;
                p+=tok[r--];
            }
            else
                break;
        }
        return res;
    }
};