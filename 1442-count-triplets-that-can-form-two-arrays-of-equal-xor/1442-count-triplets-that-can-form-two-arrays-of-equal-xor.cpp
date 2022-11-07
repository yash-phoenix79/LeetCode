class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        arr.insert(arr.begin(),0);// To Calculate prefix XOR array
        int n=arr.size();
        for(int i=1;i<n;i++) //Calculation of XOR array
            arr[i]^=arr[i-1];
        
        int res=0;
        for(int i=0;i<n;i++){
            for(int k=i+1;k<n;k++){
                if(arr[i]==arr[k])     // All pair combinations that make answer
                    res+=(k-i-1);
            }
        }
        
        return res;
        
    }
};