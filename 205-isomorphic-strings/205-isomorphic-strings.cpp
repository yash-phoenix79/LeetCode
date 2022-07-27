class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>m1(256,-1),m2(256,-1);
        for(int i=0;i<s.size();i++)
        {
            if(m1[s[i]-'\0']!=m2[t[i]-'\0'])
                return false;
            m1[s[i]-'\0']=m2[t[i]-'\0']=i;
        }
        return true;
    }
};