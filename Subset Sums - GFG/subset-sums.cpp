// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

void findSum(vector<int>arr,int i,int N,vector<int>&ans,int sum){
    if(i==N){
        ans.push_back(sum);
         return;
    }
   
   findSum(arr,i+1,N,ans,sum);
   sum+=arr[i];
   findSum(arr,i+1,N,ans,sum);
    
}

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        
        vector<int>ans;
        int sum=0;
        
        findSum(arr,0,N,ans,sum);
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends