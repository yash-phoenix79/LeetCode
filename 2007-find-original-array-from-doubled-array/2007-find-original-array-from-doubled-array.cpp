class Solution {
public:
    vector<int> findOriginalArray(vector<int>& chan) {
     int n=chan.size();
        if(n%2)return {};
        
        sort(begin(chan),end(chan));
        unordered_map<int,int>m;
        
        for(auto x:chan)
            m[x]++;
        
        vector<int>res;
        for(int i=0;i<n;i++){
            if(m[chan[i]]==0)continue;
            else if(m[2*chan[i]]==0)return {};
            res.push_back(chan[i]);
            m[chan[i]]--;
            m[2*chan[i]]--;
        }
        return res;
    }
};