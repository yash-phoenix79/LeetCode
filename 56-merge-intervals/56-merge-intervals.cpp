class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>>ans;
        sort(in.begin(),in.end());
        int n=in.size();
        int i=0;
        
        while(i<n){
            vector<int>temp;
            
            int fir=in[i][0];
            int sec=in[i][1];
            if(i+1>=n)
            {
                int sec=in[n-1][1];
                temp={fir,sec};
            ans.push_back(temp);
                break;
            }
            while(i+1<n&&sec>=in[i+1][0]){
                sec=max(sec,in[i+1][1]);
                 i++;
                
            }

             
            
            temp={fir,sec};
            ans.push_back(temp);
            i++;
        }
        return ans;
    }
};