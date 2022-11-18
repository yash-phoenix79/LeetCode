class Solution {
public:
    int openLock(vector<string>& de, string tar) {
        
        unordered_set<string>ds(begin(de),end(de));
        unordered_set<string>vis;
        
        if(ds.find("0000")!=ds.end())
            return -1;
        
        queue<string>q;
        q.push("0000");
        
        vis.insert("0000");
        
        int res=0;
        
        while(!q.empty()){
            
            int n=q.size();
            while(n--){
                string up,down,t=q.front();
                q.pop();
                
                if(t==tar)
                    return res;
                char u,d;
                for(int i=0;i<4;i++){
                    
                    up=down=t;
                    u=d=t[i];
                    
                    up[i]=(u=='9')?'0':u+1;
                    down[i]=(d=='0')?'9':d-1;
                    
                  if(vis.find(up)==vis.end()&&ds.find(up)==ds.end()){
                      vis.insert(up);
                      q.push(up);
                  }  
                   
                    if(vis.find(down)==vis.end()&&ds.find(down)==ds.end()){
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