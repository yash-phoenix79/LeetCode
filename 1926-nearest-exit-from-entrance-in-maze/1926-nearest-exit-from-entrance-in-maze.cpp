class Solution {
public:
    int d[5]={1,0,-1,0,1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
         queue<pair<int,int>>q;
          q.push({ent[0],ent[1]});
        
        int ans=1;
        int n=maze.size();
        int m=maze[0].size();
       
        maze[ent[0]][ent[1]]='+';
        while(!q.empty()){
            int sz=q.size();
           
            while(sz--){
                auto cur=q.front();
                q.pop();
                int x=cur.first;
                int y=cur.second;
               
                for(int i=0;i<4;i++){
                    int dx=x+d[i];
                    int dy=y+d[i+1];
                    if(dx<0||dy<0||dx>=n||dy>=m||maze[dx][dy]=='+')
                        continue;
                 
                        if((dx==0||dy==0||dx==n-1||dy==m-1))
                            return ans;
                          maze[dx][dy]='+';
                             q.push({dx,dy});
                           
                
                }
            }
             ans++;
        }
        return -1;
    }
};