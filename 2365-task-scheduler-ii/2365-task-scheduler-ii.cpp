class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long>m;
        long long res=0;
        
        for(auto x:tasks){
            if(m.find(x)!=m.end()){
                m[x]=res=max(res,m[x]+space)+1;
            }
            else
                m[x]=++res;
        }
        return res;
    }
};