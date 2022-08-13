class Solution {
public:
    
    bool check(unordered_map<string,int>m,string s,int len){
        for(int i=0;i<s.length();i+=len){
            string t=s.substr(i,len);
            if(m.find(t)!=m.end()){
                if(--m[t]==-1)
                    return false;
            }
            else
                return false;
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
          vector<int>res;
        
        int wordLen=words[0].size();
        int Len=s.length();
        int windowSize=words.size()*wordLen;
        
        unordered_map<string,int>m;
        for(auto x:words)
            m[x]++;
        
        int i=0;
        while(i+windowSize<=Len){
            if(check(m,s.substr(i,windowSize),wordLen))
                res.push_back(i);
            i++;
        }
        return res;
        
    }
};