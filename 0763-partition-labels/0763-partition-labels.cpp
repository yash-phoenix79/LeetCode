class Solution {
public:
    vector<int> partitionLabels(string s) {
     
        vector<int>res;
        
        vector<int>al(26,-1);
        int n=s.length();
        
        for(int i=0;i<n;i++){
            
            al[s[i]-'a']=i;
            
        }
        
        int i=0;
        
        while(i<n){
            
            int sz=al[s[i]-'a'];
            
            int t=i;
            
            while(i<=sz){
                
                if(al[s[i]-'a']<=sz){
                    i++;
                    
                }
                else{
                    sz=al[s[i]-'a'];
                    i++;
                    
                }
                    
                
            }
            i=sz+1;
            res.push_back(sz-t+1);
            
        }
        
        return res;
        
    }
};