class Solution {
public:
    bool canConstruct(string ran, string maga) {
        unordered_map<char,int>m;
        
        for(int i=0;i<maga.size();i++)
            m[maga[i]]++;
        for(int i=0;i<ran.size();i++){
            if(m[ran[i]]>0)
                m[ran[i]]--;
            else
                return false;
        }
        return true;
    }
};