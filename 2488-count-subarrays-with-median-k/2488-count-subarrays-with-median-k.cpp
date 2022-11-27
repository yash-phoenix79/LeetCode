class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            
            if(nums[i]==k)
                nums[i]=0;
            else if(nums[i]>k)
                nums[i]=1;
            else
                nums[i]=-1;
            
        }
        
        
        unordered_map<int,int>m;
        
        int sum=0,res=0;
    
        int idx=-1;
        for(int i=0;i<n;i++){
            
            if(nums[i]==0){
                idx=i;
                break;
            }
            
        }
        
        
        for(int i=idx;i>=0;i--){
            
            sum+=nums[i];
            m[sum]++;
            // cout<<nums[i]<<" ";
        }
        cout<<endl;
        int t;
        sum=0;
        for(int i=idx;i<n;i++){
            sum+=nums[i];
            t=-1*sum;
            res+=m[t];
            res+=m[t+1];
            
//              cout<<nums[i]<<" ";
            
        }
        return res;
        
    }
};