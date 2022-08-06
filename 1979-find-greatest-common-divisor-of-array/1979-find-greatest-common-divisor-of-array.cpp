class Solution {
public:
    
    int gcd(int a,int b){
        
        if(b==0)
            return a;
        
        return gcd(b,a%b);
    }
    
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        
        int maxi=*max_element(begin(nums),end(nums));
        int mini=*min_element(begin(nums),end(nums));
        
        return gcd(maxi,mini);
        
    }
};