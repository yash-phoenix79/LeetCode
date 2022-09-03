class Solution {
public:
    int mostWordsFound(vector<string>& sen) {
        int res=0;
        
        for(int i=0;i<sen.size();i++){
            int cnt=count(sen[i].begin(),sen[i].end(),' ')+1;
             res=max(res,cnt);
        }
           
        return res;
    }
};