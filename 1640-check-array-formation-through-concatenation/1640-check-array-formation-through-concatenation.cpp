class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n=arr.size();
        for(int i=0;i<pieces.size();i++){
            if(find(arr.begin(),arr.end(),pieces[i][0])==arr.end())
                return false;
            else{
                int idx=find(arr.begin(),arr.end(),pieces[i][0])-arr.begin();
                cout<<idx<<endl;
                for(int j=0;j<pieces[i].size();j++){
                    cout<<pieces[i][j]<<" "<<arr[idx+j]<<endl;
                    if(idx+j>n||pieces[i][j]!=arr[idx+j])
                        return false;
                }
            }
        }
        return true;
    }
};