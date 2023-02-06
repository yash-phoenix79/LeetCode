class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
        
        for(auto x:l){
            if(x>t)
                return x;
        }
        
        return l[0];
        
    }
};