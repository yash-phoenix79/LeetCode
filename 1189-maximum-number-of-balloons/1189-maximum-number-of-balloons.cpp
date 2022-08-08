class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        string s="balloon";
      vector<int>alpha(26,0);
        for(char c:text)
            alpha[c-'a']++;
        
        int res=0;
        
        while(1){
            if(alpha[1]<=0)
                break;
            else
                alpha[1]--;
            
            if(alpha[0]<=0)
                break;
            else
                alpha[0]--;
            
            if(alpha[13]<=0)
                break;
            else
                alpha[13]--;
            
            if(alpha[11]<=1)
                break;
            else
                alpha[11]-=2;
            
            if(alpha[14]<=1)
                break;
            else
                alpha[14]-=2;
                    
            res++;
        }
        return res;
    }
};