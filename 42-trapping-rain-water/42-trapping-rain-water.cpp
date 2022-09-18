class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        
        int maxL=height[0],maxR=height[n-1];
        
        int res=0;
        while(l<=r){
            maxL=max(maxL,height[l]);
            maxR=max(maxR,height[r]);
            if(maxL<=maxR){
                res+=(maxL-height[l++]);
               
            }
            else
                res+=(maxR-height[r--]);
        }
        return res;
    }
};