// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    
    bool isSafe(int i,int j,vector<vector<int>> &m,int n){
        if(i<0||j<0||i>=n||j>=n||m[i][j]!=1)
        return false;
        return true;
    }
    
    void findPathHelper(int i,int j,vector<vector<int>> &m,int n,string path,int dx[],int dy[]){
        if(i==n-1&&j==n-1){
            ans.push_back(path);
            return;
        }
        
        string d="DLRU";
        
        for(int k=0;k<4;k++){
            if(isSafe(i+dx[k],j+dy[k],m,n)){
                m[i][j]=2;
                findPathHelper(i+dx[k],j+dy[k],m,n,path+d[k],dx,dy);
                m[i][j]=1;
            }
        }
        
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        if(m[0][0]==0)
        return ans;
        
        findPathHelper(0,0,m,n,"",dx,dy);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends