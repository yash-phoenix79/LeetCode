class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& ro, int ad) {
        long long int a=ad;
        long long int n=ro.size();
        for(long long int i=0;i<n;i++){
            capacity[i]-=ro[i];
        }
        
        sort(capacity.begin(),capacity.end());
        
        long long int cnt =0;
       long long int i=0;
        
        while(i<n&&capacity[i]==0){
            i++;
            cnt++;
        }
        
        while(i<n&&a){
            if(capacity[i]<=a)
                  cnt++;
                a-=capacity[i];
          
            i++;
        }
        return (int)cnt;
    }
};