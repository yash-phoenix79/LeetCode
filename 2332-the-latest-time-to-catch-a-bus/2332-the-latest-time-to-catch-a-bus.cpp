class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& bus, vector<int>& pas, int cap) {
     int n=bus.size();
        int m=pas.size(),i,j=0;
        
        int c;
        
      int prev=-1;
        sort(begin(bus),end(bus));
        sort(begin(pas),end(pas));
        int ans;
        for(i=0;i<n;i++){
            c=0;
            while(c<cap&&j<m&&bus[i]>=pas[j]){
                if(prev!=pas[j]-1)
                {
                    ans=pas[j]-1;
                   
                }
                 prev=(pas[j]);
                c++;
                j++;
            }
            if(c<cap&&prev!=bus[i])
                ans=bus[i];
        }
        return ans;
    }
};