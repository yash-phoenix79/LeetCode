class Solution {
public:
    long long countVowels(string word) {
        
        long long res=0;
        int n=word.length();
        
        for(int i=0;i<n;i++){
            if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u')
                res+= (long long)(n-i)*(long long)(i+1);
        }
        
        return res;
        
    }
};