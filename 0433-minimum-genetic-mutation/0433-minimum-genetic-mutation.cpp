class Solution {
public:
    
    char c[4]={'A','C','G','T'};
    
    int minMutation(string st, string e, vector<string>& bank) {
        
        if(find(begin(bank),end(bank),e)==end(bank))return -1;
        
        
        queue<pair<string,int>>q;
        q.push({st,0});
        
        while(!q.empty()){
            
            auto cur=q.front();
            q.pop();
            string s=cur.first;
            int dis=cur.second;
            if(s==e)
                return dis;
            
            for(int i=0;i<8;i++){
                
                for(int j=0;j<4;j++){
                    
                    if(s[i]!=c[j]){
                        string t=s;
                        t[i]=c[j];
                        auto it=find(begin(bank),end(bank),t);
                        if(it!=end(bank)){
                            q.push({t,dis+1});
                            bank.erase(it);
                        }
                    }
                    
                }
                
            }
            
        }
        return -1;
        
    }
};