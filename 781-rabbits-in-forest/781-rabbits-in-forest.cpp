class Solution {
public:
    int numRabbits(vector<int>& ans) {
        int res=0;
        unordered_map<int,int>m;
        for(auto x:ans){
            if(x==0)res++;
            else{
                if(m[x]==0)res+=x+1;
                m[x]++;
                if(m[x]==x+1)m[x]=0;
            }
        }
        return res;
    }
};