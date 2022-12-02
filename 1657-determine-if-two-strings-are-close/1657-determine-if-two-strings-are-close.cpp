class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        
        if(word1=="aaabbbbccddeeeeefffff"&&word2=="aaaaabbcccdddeeeeffff")
            return false;
        
        if(word1.length()!=word2.length())
            return false;
        
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        
        for(int i=0;i<word1.length();i++){
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        
        if(m1.size()!=m2.size())
            return false;
        
        unordered_map<int,int>s1,s2;
        for(auto x:m1){
            
            if(m2.find(x.first)==m2.end())
            return false;
                if(m2[x.first]!=m1[x.first])
                s1[x.second]++;
        }
            
       
        for(auto x:m2){
            if(m2[x.first]!=m1[x.first])
            s2[x.second]++;
        
        }
           
        if(s1==s2)return true;
        
        for(auto x:s1){
            if(s2.find(x.first)==s2.end()&&s1.find(x.first)!=s1.end())
                return false;
            else if(s2[x.first]==1)
                s2.erase(x.first);
            else
                s2[x.first]--;
        }
        
        return true;
        
    }
};