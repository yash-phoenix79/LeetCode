class Solution {
public:
    bool detectCapitalUse(string w) {
        
        int n=w.length();
        
        if(islower(w[0])){
            
            int i=1;
            for(;i<n;i++)
                if(isupper(w[i]))
                    return false;
                return true;
            
        }
        
         if(islower(w[1])){
            
            int i=2;
            for(;i<n;i++)
                if(isupper(w[i]))
                    return false;
                return true;
            
        }
        
        int i=2;
        for(;i<n;i++)
            if(islower(w[i]))
                return false;
        return true;
        
    }
};