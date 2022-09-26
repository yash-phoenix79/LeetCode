class Solution {
public:
    vector<int> parent;
    
    void join(int u, int v){
        u=findPar(u); v=findPar(v);
        if(u!=v) parent[u]=v;
    }
    
    int findPar(int a){
        if(parent[a]!=a){
            parent[a]=findPar(parent[a]);
        }
        return parent[a];
    }
    
    bool equationsPossible(vector<string>& equ) {
        for(int i=0; i<26; i++) parent.push_back(i);
        for(auto a:equ){
            if(a[1]=='!' || a[0]==a[3]) continue;
            else{
                join(a[0]-'a', a[3]-'a');
            }
        }
        
        for(auto a:equ){
            if(a[1]=='!'){
                if(findPar(a[0]-'a')==findPar(a[3]-'a'))
                    return false;
            }
        }
        return true;
    }
};