class Solution {
public:
    //as we were told to find the max. difference of two successive elements when they get sorted but with actually applying typical sort algorithm
    // we imply the use of sorting algorithm with no comparator 
    
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return 0;
        // finding max and min element to find the value of average gap/interval
        int maxi=*max_element(begin(nums),end(nums)); 
        int mini=*min_element(begin(nums),end(nums));
        
       
        int inter=(int)ceil((float)(maxi-mini)/(n-1)); //average interval is found by taking the ceil value function
        cout<<inter<<endl;
        
        int bu=n-1;// number of intervals
        
        vector<int>mx(bu,-1);
        vector<int>mi(bu,INT_MAX);
        
        for(int i=0;i<n;i++){
            if(nums[i]==mini||nums[i]==maxi)
            {
                continue;
            }
            int val=(nums[i]-mini)/inter;
           mx[val]=max(mx[val],nums[i]);
           mi[val]=min(mi[val],nums[i]);
            
        }
        
        
        int prev=mini;
        int res=0;
        
        for(int i=0;i<bu;i++){
            if(mx[i]==-1)continue;
            res=max(res,mi[i]-prev);
            prev=mx[i];
        }
        
        res=max(maxi-prev,res);
        
        return res;
    }
};