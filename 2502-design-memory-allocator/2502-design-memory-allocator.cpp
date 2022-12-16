class Allocator {
public:
    
    vector<int>mem;
    int sz;
    unordered_map<int,vector<int>>m;
    
    Allocator(int n) {
        mem.resize(n);
        sz=n;
    }
    
    int allocate(int size, int mID) {
        
        int idx,free=0;
        
        for(int i=0;i<sz;i++){
            
            if(free==0)idx=i;
            if(mem[i]==0)free++;
            else free=0;
                
            if(free>=size)break;
            
        }
        
        if(free>=size){
            for(int i=idx;i<idx+size;i++)
            {
                mem[i]=mID;
                m[mID].push_back(i);
            }
        }
        
        return free>=size?idx:-1;
        
    }
    
    int free(int mID) {
        
        int cnt=0;
        for(auto it:m[mID]){
            cnt++;
            mem[it]=0;
        }
        m.erase(mID);
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */