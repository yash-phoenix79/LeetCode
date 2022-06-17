class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int diff=arr[1]-arr[0];
        
         vector<vector<int>>res;
        
        res.push_back({arr[0],arr[1]});
        
        for(int i=2;i<n;i++){
            if(arr[i]-arr[i-1]==diff){
                res.push_back({arr[i-1],arr[i]});
            }
            else if(arr[i]-arr[i-1]<diff){
                diff=arr[i]-arr[i-1];
                res.clear();
                res.push_back({arr[i-1],arr[i]});
            }
        }
        return res;
    }
};