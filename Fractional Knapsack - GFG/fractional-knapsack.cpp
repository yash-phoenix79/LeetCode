// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        double ans=0;
        vector<pair<double,double>>knap(n);
        
        for(int i=0;i<n;i++)
        knap[i]={(double)arr[i].value/arr[i].weight,(double)arr[i].weight};
        
        sort(knap.begin(),knap.end(),[](const pair<double,int>&p1,const pair<double,int>&p2){
           return p1.first>p2.first; 
        });
        
      for(int i=0;i<n;i++){
          if(W<0)
          break;
          else if(W>=knap[i].second){
              ans+=(knap[i].first*knap[i].second);
              W-=knap[i].second;
          }
          else{
              ans+=(knap[i].first*W);
              W=0;
          }
      }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends