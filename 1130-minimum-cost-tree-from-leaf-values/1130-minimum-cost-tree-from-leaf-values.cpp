class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
       
        int res=0;
        while(arr.size()>1){
            int t=INT_MAX;
            int mini=-1;
            for(int i=1;i<arr.size();i++)
            {

                if(arr[i]*arr[i-1]<t){
                    mini=arr[i]<arr[i-1]?i:i-1;
                    t=arr[i]*arr[i-1];
                }
            }
            res+=t;
            arr.erase(arr.begin()+mini);
        }
        return res;
    }
};