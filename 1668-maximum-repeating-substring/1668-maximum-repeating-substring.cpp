class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int res=0;
        string t=word;
        while(sequence.find(t)!=string::npos){
            res++;
            t+=word;
        }
        return res;
    }
};