// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        vector<pair<int,int>>jobs(n);
        int maxi=0;
        for(int i=0;i<n;i++){
            jobs[i]={arr[i].profit,arr[i].dead};
            maxi=max(maxi,arr[i].dead);
        }
        
        sort(jobs.begin(),jobs.end(),[](const pair<int,int>&p1,const pair<int,int>&p2){
            if(p1.first==p2.first)
            return p1.second<p2.second;
            return p1.first>p2.first;
        });
        
        vector<int>slot(maxi,-1);
        
        int cnt=0,prof=0;
        for(int i=0;i<n;i++){
            int d=jobs[i].second;
            for(int j=d;j>=0;j--){
                if(slot[j-1]==-1)
                {
                    slot[j-1]=1;
                    cnt++;
                    prof+=jobs[i].first;
                    break;
                }
            }
        }
        return {cnt,prof};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends