class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int i=0,j=height.size()-1;
        int maxL=height[i],maxR=height[j];
        
        while(i<j){
            maxL=max(maxL,height[i]);
            maxR=max(maxR,height[j]);
            if(maxL<=maxR){
                ans+=(maxL-height[i]);
                i++;
           }
            else{
                ans+=(maxR-height[j]);
                j--;
            }
        }
        return ans;
    }
};