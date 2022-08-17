class Solution {
public:
    vector<string>morse={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        
        int res=0;
        unordered_set<string>s;
        for(auto x:words){
            string temp="";
            for(auto y:x)
                temp+=morse[y-'a'];
            s.insert(temp);
        }
        return s.size();
    }
};