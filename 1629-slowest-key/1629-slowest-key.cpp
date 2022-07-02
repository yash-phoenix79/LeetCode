class Solution {
public:
    char slowestKey(vector<int>& rel, string key) {
        
        int maxi=rel[0];
        char res=key[0];
        
        for(int i=1;i<rel.size();i++){
            if(rel[i]-rel[i-1]>maxi){
                maxi=rel[i]-rel[i-1];
                res=key[i];
            }
            else if(rel[i]-rel[i-1]==maxi){
                if(key[i]>res)
                    res=key[i];
            }
        }
        return res;
    }
};