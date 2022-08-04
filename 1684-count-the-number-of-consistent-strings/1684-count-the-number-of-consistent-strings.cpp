class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n=words.size();
        unordered_set<char>s;
        for(auto x:allowed)
            s.insert(x);
        
        int res=0;
        
        for(int i=0;i<n;i++){
            bool present=true;
            for(auto x:words[i]){
                if(s.count(x)==0){
                    present=false;
                    break;
                }
            }
            if(present)
                res++;
        }
        return res;
    }
};