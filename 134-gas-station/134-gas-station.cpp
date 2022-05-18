class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     int n=gas.size();
        
        int tot=0,cur=0,start=0;
        
        
        for(int i=0;i<n;i++){
            tot+=(gas[i]-cost[i]);
            cur+=(gas[i]-cost[i]);
            if(cur<0){
                cur=0;
                start=i+1;
            }
        }
        
        if(tot<0)return -1;
        
        return start;
        
    }
};