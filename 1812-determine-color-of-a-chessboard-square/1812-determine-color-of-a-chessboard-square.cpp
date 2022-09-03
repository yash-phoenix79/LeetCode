class Solution {
public:
    bool squareIsWhite(string cor) {
        int x=cor[0]-'a';
        int y=cor[1]-'1';
        
        if((x%2==0&&y%2==0)||(x%2!=0&&y%2!=0))
            return false;
        return true;
    }
};