class Solution {
public:
    int openLock(vector<string>& dead, string tar) {
       
        unordered_set<string>de(begin(dead),end(dead));
        unordered_set<string>vis;
        
         int res=0;
        
        if(de.find("0000")!=de.end())
            return -1;
        
        queue<string>q;
        q.push("0000");
        vis.insert("0000");
        
        while(!q.empty()){
            
            int n=q.size();
            while(n--){
                string up,down,t=q.front();
                q.pop();
                
                if(t==tar)
                    return res;
                for(int i=0;i<4;i++){
                    up=t,down=t;
                    char u=up[i],d=down[i];
                    
                    up[i]=(u=='9'?'0':u+1);
                    down[i]=(d=='0'?'9':d-1);
                   
                    if(vis.find(up)==vis.end()&&(de.find(up)==de.end())){
                        vis.insert(up);
                        q.push(up);
                    }
                    
                    if(vis.find(down)==vis.end()&&(de.find(down)==de.end())){
                        vis.insert(down);
                        q.push(down);
                    }
                    
                }
                
            }
            res++;
        }
        
        return -1;
        
    }
};