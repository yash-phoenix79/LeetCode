class Solution {
public:
    int maximumSwap(int num) {
        string t=to_string(num);
        string s=t;
        sort(begin(t),end(t),greater<int>());
        // 
        
        for(int i=0;i<t.size();i++){
            if(s[i]!=t[i]){
                int j=t.size()-1;
                
                while(j!=i){
                    if(s[j]==t[i]){
                        swap(s[i],s[j]);
                        break;
                    }
                    j--;    
                }
                
                break;
            }
            
        }
        return stoi(s);
    }
};