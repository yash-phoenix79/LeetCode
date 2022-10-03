class Solution {
public:
    int minCost(string col, vector<int>& time) {
        int n=col.size();
        
        int cur=0,res=0;
        while(cur<n){
            int maxi=INT_MIN;
            int sum=0,idx=cur;
            while(cur<n&&col[idx]==col[cur]){
                sum+=time[cur];
                maxi=max(maxi,time[cur]);
                cur++;
            }
            sum-=maxi;
            res+=sum;
            
        }
        return res;
    }
};