class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        
        int n=in.size();
        
        sort(begin(in),end(in),[](auto &a,auto &b){
           return a[1]<b[1]; 
        });
        
        int res=0,prev=in[0][1];
        
        for(int i=1;i<in.size();i++){
            
            if(prev>in[i][0])
                res++;
            else
                prev=in[i][1];
            
        }
        return res;
    }
};