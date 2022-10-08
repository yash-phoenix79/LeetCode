class Solution {
public:
    bool equalFrequency(string word) {
        
        int n=word.size();
        
        
        
        for(int i=0;i<n;i++){
            unordered_map<char,int>m;
            for(int j=0;j<n;j++){
                if(j!=i)
                    m[word[j]]++;
            }
            unordered_map<int,int>freq;
            for(auto x:m)
                freq[x.second]++;
            if(freq.size()==1)
            return true;
        }
        return false;
    }
};