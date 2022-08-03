class Solution {
public:
    bool judgeCircle(string moves) {
        
        int cnt1=0,cnt2=0;
        
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U')
                cnt1++;
            else if(moves[i]=='D')
                cnt1--;
            else if(moves[i]=='L')
                cnt2++;
            else
                cnt2--;
        }
        
        return cnt1==0&&cnt2==0;    
        
    }
};