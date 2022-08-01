class Solution {
public:
    
    void check(int v,vector<int>&visit,vector<vector<int>>& rooms)
    {
        visit[v]=1;
        for(auto x:rooms[v]){
            if(!visit[x])
                check(x,visit,rooms);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        
        vector<int>visit(n,0);
        
         check(0,visit,rooms);
        
        for(int i=0;i<n;i++){
            if(!visit[i])
                return false;
        }
        return true;
    }
};