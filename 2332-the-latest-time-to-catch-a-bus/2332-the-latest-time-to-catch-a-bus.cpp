class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& bus, vector<int>& pas, int cap) {
     int n=bus.size();
        int m=pas.size(),i,j=0;
        
        int c;
        
        unordered_set<int>s;
        sort(begin(bus),end(bus));
        sort(begin(pas),end(pas));
        int ans;
        for(i=0;i<n;i++){
            c=0;
            while(c<cap&&j<m&&bus[i]>=pas[j]){
                if(s.find(pas[j]-1)==s.end())
                {
                    ans=pas[j]-1;
                   
                }
                 s.insert(pas[j]);
                c++;
                j++;
            }
            if(c<cap&&s.find(bus[i])==s.end())
                ans=bus[i];
        }
        return ans;
    }
};