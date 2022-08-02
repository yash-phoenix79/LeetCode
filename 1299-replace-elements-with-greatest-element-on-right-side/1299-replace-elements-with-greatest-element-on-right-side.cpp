class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxi=INT_MIN;
        int t;
        for(int i=arr.size()-1;i>=0;i--){
            t=arr[i];
            if(i==arr.size()-1)
                arr[i]=-1;
            else
                arr[i]=maxi;
            maxi=max(maxi,t);
        }
        return arr;
    }
};